#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Maze.h"

using namespace std;

void SplashScreen();
void PrintInstructions();

void main()
{
	try {
		string input;
		bool dead = false;
		SplashScreen();
		cout << "Welcome to Maze Explorer!" << endl;

		cout << "..";
		Maze* maze = new Maze;
		cout << "\nThe world begins to return to focus as you slowly wake up,\na throbbing in your head. "
			<< "Everything seems blurry at first but as you\nslowly start to sit up everything comes into focus.\n"
			<< "You appear to be in an abandoned house, or well\nperhaps the word shack is a better description of it.\nA soft light pours through\n"
			<< "slanted, dilapidated, and rotting wooden walls\nthat support a roof that seems to mirror the walls.\nAn old door clings to it's hinges\n"
			<< "on one wall of the ruined structure.\nSeveral pieces of ancient furniture lies around you\nas you stand up. You dig back into your memories\n"
			<< "To see if you can remember how you got\nhere but it's all just a blur.\nThe only thing you remember is your name, '" << maze->GetPlayer()->getName() << "'" << endl;

		cout << "\nFor help on how to play type 'help'\n";
		cout << "> ";
		cin >> input;
		while (input != "0")
		{
			if (!dead && !maze->HasWon())
			{
				if (input == "help")
				{
					PrintInstructions();
				}
				else if (!maze->GetPlayer()->IsBattling())
				{
					if (maze->GetPlayer()->getHealth() <= 0)
					{
						dead = true;
					}
					else
					{
						Command cmd = maze->parseCommand(input);
						if (cmd != Command::null)
						{
							maze->IssueCommand(cmd);
						}
						else
						{
							cout << "Error; Invalid command!" << endl;
						}
					}
				}
				else
				{
					if (maze->GetPlayer()->getHealth() <= 0)
					{
						dead = true;
					}
					else
					{
						maze->EndBattle();
					}
				}
				if (!dead && !maze->HasWon() && !maze->GetPlayer()->IsBattling())
				{
					cout << "> ";
					cin >> input;
				}
			}
			else if (dead)
			{
				cout << "As the world blacks out around you the faintest image of that angel statue flashes in your mind, standing above you as your eyes close." << endl;
				cout << "/nYou have died! Oh well, try again next time!" << endl;
				system("pause");
				return;
			}
			else
			{
				cout << "Thanks for playing! See you later. - Sean Kelly" << endl;
				system("pause");
				return;
			}
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		system("pause");
		return;
	}
}

void PrintInstructions()
{
	cout << "Help Menu:" << endl;
	cout << "\n0 - Quit the game (There is no saving!)" << endl;
	cout << "n - head north" << endl;
	cout << "e - head east" << endl;
	cout << "s - head south" << endl;
	cout << "w - head west" << endl;
	cout << "l - look at the room you are in" << endl;
	cout << "i - interact with the room you're in" << endl;
	cout << "me - Inspect yourself" << endl;
}

void SplashScreen()
{
	cout << "===================================" << endl;
	cout << "Welcome to" << endl;
	cout << endl;
	cout << "  __  __                 ______            _                     " << endl;
	cout << " |  \\/  |               |  ____|          | |                    " << endl;
	cout << " | \\  / | __ _ _______  | |__  __  ___ __ | | ___  _ __ ___ _ __ " << endl;
	cout << " | |\\/| |/ _` |_  / _ \\ |  __| \\ \\/ / '_ \\| |/ _ \\| '__/ _ \\ '__|" << endl;
	cout << " | |  | | (_| |/ /  __/ | |____ >  <| |_) | | (_) | | |  __/ |   " << endl;
	cout << " |_|  |_|\\__,_/___\\___| |______/_/\\_\\ .__/|_|\\___/|_|  \\___|_|   " << endl;
	cout << "                                    | |                          " << endl;
	cout << "                                    |_|                          " << endl;
	cout << endl;
	cout << "by Sean Kelly" << endl;
	cout << "===================================" << endl;
	cout << "Please wait..." << endl;
	_sleep(10000);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//redesign (more or less). Each room will have 1 entry and 1 exit, with the exception of mphead

//void Init(Maze* maze)
//{
//	if (maze->GetHead() == 0)
//	{
//		RoomFactory* factory = new RoomFactory();
//
//
//		factory->WithName("h1");
//		factory->AddItem(new Item("House Key", 1));
//		maze->SetHead(factory->BuildRoom());
//		maze->SetTail(maze->GetHead());
//		
//		maze->GetPlayer()->setRoom(maze->GetHead());
//
//		factory->WithName("f1");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::NORTH);
//
//		factory->WithName("reset");
//		factory->SetDesc("The Shrine\n\nYou appear to be in a clearing, above you the moon shining gently through as you look around. The only thing of note in the clearing is rather eerie; a large, grey, stone-carved statue about twice your height depicting a hooded figure with angelic wings. It holds its hands out with palms turned upward, facing the moon as if expecting it to pour water down upon it's hands. Several candles are list around the base of the statue, it's plinth coming up to your waist.");
//		factory->AddItem(new Item("A Strange Key", 1));
//		maze->SetReset(factory->BuildRoom());
//		maze->AddRoom(maze->GetReset(), Direction::NORTH);
//
//		factory->WithName("f2");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::EAST);
//
//		factory->WithName("f3");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::EAST);
//
//		factory->WithName("f4");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::SOUTH);
//
//		factory->WithName("f5");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::WEST);
//
//		factory->WithName("f6");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		maze->AddRoom(factory->BuildRoom(), Direction::SOUTH);
//
//		factory->WithName("f7");
//		factory->SetDesc("The Forest\n\nDark woods surround you, several possible paths to choose from, all just barely too dark to see through...\n");
//		factory->AddItem(new Weapon("The Sword of Power", 10));
//		maze->AddRoom(factory->BuildRoom(), Direction::SOUTH);
//	}
//}