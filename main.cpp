/*
Number Game
By: Erik Rodabaugh
Website: www.ErikRodabaugh.com
Copyright (C) 2016 Erik Rodabaugh

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

// Setup.
#include <iostream>
#include <unistd.h> // Has Sleep.
using namespace std;

// Variables.
int used[1000000], current = 0, fail = 0, input, wait, a, last;

int main()
{
  // Display the title.
  cout << "Number Game" << endl << "By: Erik Rodabaugh" << endl << "Website: www.ErikRodabaugh.com" << endl;

  // Create a while loop that runs until the user fails.
  while(fail == 0){
    // Set last to equal input, before asking for new input.
    last = input;

    // Tell the user how many rounds they have completed, and ask for a new number.
    cout << endl << "Rounds: " << current << endl << "Enter a number you have not used before, and is not simply 1 greater than the last number: ";
    cin >> input;
    cout << endl;

    // Check to see if the user has used the new number before.
    for (a=0; a < current+1; a++){
      if (used[a] == input){
	fail = 1;
	  break;
      }
    }

    // If this is not round 1, then check to see if the user is just adding one to their answer each time.
    if(current != 0){
      if(last+1 == input){
	fail = 2;
      }
    }

    // Check to see if the user has failed or not. If they have, tell them how.
    if (fail == 0){
      used[current] = input;
      cout << "Well done!" << endl;
    }else if (fail == 1){
      cout << "You have used " << input << " before.";
    }else if (fail == 2){
      cout << "That is simply 1 greater than the last number you used.";
    }
    current++;
  }

  // Output a game over, and wait for the user to close the program.
  cout << endl << "Game Over!";
  cin >> wait;
}
