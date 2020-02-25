#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<limits>
using namespace std;

class HP 
{
	public:
		int health; 

};


class S // this is the screen class 
{
	public:
		int SC;
		void b(void)
		{


			SC = 0;
			while (SC<31)
			{
				cout<<"\n";
				SC++;
			}



		}

};





int main(){
srand(time(NULL));

// Dragon's Health 
HP DH; 
HP hp;
DH.health = 100; 

//int DH=100;
// Dragon's attack 
int DA=10; 
int shield =10; 
// int hp = 10;
hp.health = 10;  
int attack =10; 
char wait;
char choice ='0';
int dice =0; 
float Dice = 0.0; 
int magic =0;
int New_magic =0; 
int damage = 0;
int turn = 1;
// Poison damage
int PD = 0;
int magic_on =0;
//stop time 
int ST =0; 
int freeze = 0;
//screen clear 
int SC =0;
S s;
cout<<""<<endl; 

s.b();


cout<<"Weclome to the game!"<<endl; 
cout<<"to become THE DRAGON SLAYER!!!"<<endl; 
cout<<"You have 5 days to prepare for a battle. Then you fight a dragon!"<<endl;
cout<<"This game will give you choices in numbers."<<endl;
cout<<"To slect a choice, press the choice number (Example: 3) on your keyboard, and press Enter."<<endl;


cout<<"Let's start!\n(press any key to begin)"<<endl; 
cin >> wait;
// reset the choice
choice = 'a';
while((choice != '1')&&(choice!='2')&&(choice!='3')&&(choice!='4'))
{
// clear screen
//

s.b();
	cout<<"Day 1"<<endl; 
	cout<<"Many towns and cities have been raided by a dragon and this time it was your town.\nYou go to the castle to inform the damage.\nYou are fierce with anger.\nSo the king has orderd you to defeat the dragon."<<endl; 

	cout<<"You agree, and you go back to your town."<<endl; 




	cout<<"Now you need to prepare to defeat the dragon!"<<endl; 

	cout<<"What will you do next?"<<endl; 

	cout<<"1.) Prepare food"<<endl; 
	cout<<"2.) Craft a sword"<<endl; 
	
	cout<<"3.) Go to the old shaman's house to learn some magic"<<endl; 
	cout<<"4.) Craft a shield"<<endl; 


	cout<<"Input either 1,2,3,or,4 (your choice) and press Enter"<<endl; 
	cin>> choice; 
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

s.b();

		if (choice == '1')
			{
			hp.health = hp.health + 10; 
			cout<<"You made extra food to eat now, and extra for the trip"<<endl;
			cout<<"You eat the food you have just made."<<endl;
			cout<<"The food tastes very delicious and gave you energy!"<<endl; 
			cout<<"Your Health increased by 10!"<<endl;
	
			}
	
		else if(choice == '2')
			{
			cout<<"Crafting sword..."<<endl;	
			cout<<"You heat up the metal,"<<endl;	
			cout<<"hammer it for hours,"<<endl;	
			cout<<"attach a handle,"<<endl;	
			cout<<"and add some ornaments"<<endl;	
			cout<<"You finish making a sword! "<<endl;	
			
			attack = attack + 10;
			cout<<"Your attack has increased by 10!"<<endl;
	
			}


		else if (choice =='3')
			{
			 dice = rand();
			 dice = dice%100; 
				if (dice < 5)
				{		
					cout<<"You arrive at the shaman's house "<<endl;	
					cout<<"You tell her that you are preparing to defeat the dragon."<<endl;	
					cout<<"The shaman nods and brings back an old dusty box"<<endl;	
					cout<<"She dusts off the box and opens it."<<endl;	
					cout<<"A wand is inside."<<endl;	
					cout<<"The crystal of the wand is glowing."<<endl;	
					cout<<"Shaman:You are the chosen one. Here, take this with you."<<endl;	

	
				cout<<"You have attained a magin wand!\nDragon slayer's wand";
			        magic = 6;	
				}
				else if((dice>=5) && (dice<24))
				{
					cout<<"You arrive at the shaman's house"<<endl;	
					cout<<"You talk with the shaman about your plans..."<<endl;	
					cout<<"The shaman notices your bruised leg"<<endl;	
					cout<<"She murmurs some words and waves her hand around the briuse."<<endl;	
					cout<<"Your leg heals."<<endl;	
					cout<<"You ask: how did you do that?"<<endl;	
					cout<<"So she teaches you how to heal yourself."<<endl;	
	
					cout<<"You've learned the magic of heal!"<<endl;
					magic = 1;
				// uses the healing magic. 
				}
	
	
				else if((dice>=24) && (dice<43))
				{
					cout<<"You arrive at the shaman's house"<<endl;	
					cout<<"You don't see her anywhere"<<endl;	
					cout<<"You keep looking"<<endl;	
					cout<<"Then suddently,"<<endl;	
					cout<<""<<endl;	
	
				cout<<"You got bitten by the shaman's pet snake!"<<endl;
			        cout<<"you grow sharp nails and leanred the magic of poison!"<< endl; 
				magic = 2; 	
	
				}
	
		
				else if((dice>=43) && (dice<62))
				{
					cout<<"You arrive at the shaman's house"<<endl;	
					cout<<"The sun was falling and the sky was getting dark."<<endl;
					cout<<"You talk about the order from the king."<<endl;	
	
				cout<<"The shaman gave you her poket watch!"<<endl; 
				cout<<"You learned time magic!\nYou learn how to bend and stop time!"<<endl;  
				magic = 3; 
	
				}
				else if((dice>=62) && (dice<81))
				{
				cout<<"The shaman and you travel up the tall winter mountain. you do training there to increase your resistivity from the cold."<<endl; 
				cout<<"a blizzard blows and you lose sight of the shaman.\nNow the two of you are separated apart"<<endl;
				cout<<"You fall into a crevasse. You try to climb up but you can't" <<endl;
				cout<<"you stive for hours, and days pass. ";
				cout<<"You still try to climb but your consciousness is fading away."<<endl;
				cout<<"Then, you faintly see the shaman flying at a distance"<<endl;
				cout<<"You reach your hand out as your consciousness fades away further..."<<endl; 
				cout<<"The shaman grabs you by the hand and takes you out of the crevasse"<<endl;
				cout<<"The shaman uses magic and gives you some heal potions. You heal."<<endl; 
				cout << "The two go back to the shaman's house where she gives you the necklace of Ice dropplet "<<endl;
				cout<<"You attain the magic if ice! Freezzing magic!"<< endl;
		
				magic = 4; 
	
	
				}
				else if((dice>=81) && (dice<100))
				{
				cout<<"The shaman gave you the ring of fire!\nYou leanred the magic of fire!"<<endl;
				magic = 5; 
				}
	
			}
	
		else if (choice == '4')
			{
			shield = shield +10; 
			cout<<"You crafted a shield!"<<endl;
			cout<<"You've gained 10 shield points!"<<endl;  
			}

	cout<<"Hit any key, then press Enter to continue...";
	cin>>wait;
	 cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	std::cout<<choice<<std::endl;
}


// reseting the choice.
choice = 'a';

while((choice != '1')&&(choice!='2')&&(choice!='3')&&(choice!='4'))
{

s.b();


	cout<<"Day 2"<<endl; 
	cout<<"You get on a boat to sail across the ocrean to the island where the dragon lives"<<endl; 
	
	cout<<"What will you do today?"<<endl; 


	cout<<"1.)Do some fishing from the boat"<<endl; 
	cout<<"2.)Go spear fishing "<<endl; 
	cout<<"3.)Read a book"<<endl; 
	cout<<"4.)Do physical and mental training on the boat."<<endl; 


	cin >> choice; 
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 


s.b();


	if (choice =='1')
		{
	
		cout<<"You caught some fish!"<<endl; 
	
		cout<<"Your heath went up!"<<endl;
	
		hp.health = hp.health+10;
	
		}

	if (choice =='2')
	{
	
		cout<<"You gained strength and caught some fish!"<<endl; 
		cout<<"You gained the skill of spear fishing!"<<endl;
	
		cout<<"Your attack went up!"<<endl; 
		attack = attack + 10; 
	}
	if (choice =='3')
	{


	
		cout<<"You gain some insight and knowledge about the dragon!"<<endl; 
		dice = rand(); 
		dice = dice%3; 
		if (dice == 0)
			{
			shield = shield + 10; 
	
			cout<<"You have gained more sheild points!"<<endl; 
	
			}
		else if (dice ==1)
			{
			hp.health = hp.health + 10; 
			
			cout<<"You have gained more health points!"<<endl; 
	
			}
		else if (dice == 2)
			{
			attack = attack + 10; 
			cout<<"You have gained attack points!"<<endl; 
	
			}
		else cout<<"ERROR!"<<endl;
	
	
	}
	if (choice =='4')
		{
		cout<<"The workout increased your endurance!"<<endl;
		cout<<"your sheild has gone up!"<<endl; 
		shield = shield +10; 
	
		}
	cout<<"Press any key and hit Enter to continue...";
	cin>>wait;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
}

// the } above is the end of while loop day 2

// reset the choice so the code doesn't skip. 
choice = 'a';

while((choice != '1')&&(choice!='2')&&(choice!='3')&&(choice!='4'))
{


s.b();


	cout<<"Day 3"<<endl; 
	cout<<"You arrive on the island and start walking uphill into the forest."<<endl; 
	cout<<"What will you do on day 3?"<<endl; 
	
	cout<<"1.)collect extra wood and stones"<<endl; 
	cout<<"2.)Set up your camp before the night"<<endl; 
	cout<<"3.)You come across a mushroom. It looks edible. Eat it"<<endl; 
	cout<<"4.)fight a bear!"<<endl; 
	
	
	cin >> choice; 
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	

s.b();
	
	if (choice =='1')
	{
	
	
		cout<<"You collected extra wood and stones!"<<endl; 
		cout<<"You attached those wood and stones to your shield!"<<endl;	
		cout<<"Your sheild points have increased!"<<endl;	
		shield = shield +10;
	
	}
	
	else if (choice =='2')
	{
	
		cout<<"You set up camp before the night."<<endl; 
		cout<<"you eat some beans"<<endl;	
		cout<<"You took a rest in your tent."<<endl;	
		cout<<"You gained health points!"<<endl;	
		hp.health = hp.health +10;
	}
	
	else if (choice =='3')
	{
	
	
		 dice = rand();
		 dice = dice%100; 
		if (dice < 5)
		{
			cout<<"You felt dizzy and fell asleep"<<endl;
			cout<<"In your dreams a divine voice tells you where you can find a wand."<<endl;
			cout<<"You wake up and search the place that was told to you"<<endl;
		cout<<"You have attained a magin wand!\nDragon slayer's wand";
		      New_magic = 6;	
		}
		else if((dice>=5) && (dice<24))
		{
			cout<<"You start to glow green."<<endl; 
			cout<<"You've learned the magic of heal!"<<endl;
			New_magic = 1;
			// uses the healing magic. 
		}
	
	
		else if((dice>=24) && (dice<43))
		{
			cout<<"Purple spots appear on your skin. You feel dizzy and ill."<<endl;
			cout<<"You see hallucinations"<<endl;
		        cout<<"You suffer for the rest of the day"<< endl; 
			cout<<"next morning you wake up and some how you intuiviely know how to use poison magic."<<endl;
			New_magic = 2; 	
	
		}
	
	
		else if((dice>=43) && (dice<62))
		{
			cout<<"You lose you sense of time"<<endl; 
			
			cout<<"you have no idea how fast time is going."<<endl; 
			cout<<"You cannot tell how long its been from since you ate the mushroom"<<endl; 
	
			cout<<"it feel like it's been forever since then, but also feels like it's only been seconds."<<endl; 
	
			cout<<"you see flash backs of you past, your child hood and also the future."<<endl; 
	
	
			cout<<"you wake up the next morning. Your dream has taught you time magic."<<endl; 
	
	
	
			cout<<"You've gained time magic!\nYou learn how to bend and stop time!"<<endl;  
			New_magic = 3; 
	
		}
		else if((dice>=62) && (dice<81))
		{
			
		cout<<"the surrounding start to feel a bit chilly"<<endl; 
	 	cout<<"It feels too cold for you!"<<endl;
		cout<<"You fill up a steel drum with water and place the drum over a campfire."<<endl; 
		cout<<"You wait for the water to start steaming"<<endl;
		cout<<"you go in your makeshift hot tub to warm up"<<endl;
		cout<<"The water is now boiling!"<<endl;
		cout<<"You still feel very cold."<<endl; 
		cout<<"After some time you feel your self stuck"<<endl; 
		cout<<"You look down to check the water."<<endl; 
		cout<<"The water has turned to ice!"<<endl; 
		cout<<"You have learned ice magic!"<<endl; 
		cout<<"You use your new power to break out of your drum."<<endl; 
		cout<<"The drum explodes with shards of ice flying out."<<endl;
			New_magic = 4; 
	
	
		}
		else if((dice>=81) && (dice<100))
		{
			cout<<"The mushroom was super spicy!"<<endl;
			cout<<"You literally breath fire"<<endl;
			cout<<"You've gained the fire breathing magic!"<<endl;
			New_magic = 5; 
		}
	
		if(magic !=0)
		{
			cout<<"You already have a magic.\n"<<endl;
	
			cout<<"1.)I want my new magic! Replace it with my old magic"<<endl;
		       	cout<<"2.)I want to keep my old magic. Don't replace my old magic"<<endl;
			cin>>choice;
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

			if (choice == '1')
			{
				magic  = New_magic;
			}	
			else if (choice =='2')
			{
				cout<<"You kept your old magic."<<endl;
			}
			else 
			{
				cout<<"Your old magic has been kept."<<endl;
			}
		}
		else
		{
			magic = New_magic;
		}
	
	
	}
	// end of choice 3 



	else if (choice =='4')
	{
	
		cout<<""<<endl; 
		attack = attack +10; 
	
		dice = rand();
		dice = dice%10;
			if (dice == 0)
			{
			
				cout<<"You lost the fight with the bear."<<endl;
				cout<<"you are dead.\nRun the program again to play again."<<endl;
				cout<< "GAME OVER"<<endl;
				exit(0);
			}
			else 
			{
				attack = attack*2; 
				cout<<"You won the battle with the bear!"<<endl;
				cout<<"Your attack points increased significantly!"<<endl;
	
			}
	
	
	}


	cout<<"Press any key to continue...";
	
	cin>>wait;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	
	//close for the day 3 while loop.
}
	// the one above. 

// reset the choice to avoid the code to skip 
choice = 'a';

while((choice != '1')&&(choice!='2')&&(choice!='3')&&(choice!='4'))
{



s.b();

cout<<"Day 4"<<endl; 
cout<<"You found a cave."<<endl; 

cout<<"It seems to be a shortcut to where the dragon is. You go in."<<endl; 

cout<<"What will you do in the cave?"<<endl; 
cout<<"1.)Water is dripping from the cave top. The water looks clean. Drink it."<<endl; 
cout<<"2.)You hear a loud roar. You got scared. Go out of the cave."<<endl; 
cout<<"3.)you find a deep hole in the cave. Go down the hole"<<endl; 
cout<<"4.)You found an old treasure box. You open the box."<<endl; 


cin >> choice; 
cin.ignore(numeric_limits<streamsize>::max(),'\n'); 


s.b();


if (choice =='1')
{

	cout<<"The water tastes very good\nIt was the most pure water you could find on the island."<<endl;

	cout<<"This was the water-of-life."<<endl; 

	cout<<"The scars and wounds you gained during the trip starts to heal."<<endl; 


	cout<<"You feel less tired. You were energized by the water."<<endl;


	cout<<"You gain health points"<<endl; 
		hp.health = hp.health +10;



}


if (choice =='2')
{

	cout<<"The roar was a bear from the forest"<<endl; 

	cout<<"The bear rushes towards you and slashes it's claws. It hits your face."<<endl;
	cout<<"You take damage!"<<endl; 
	cout<<"You fight back! Go for a punch!"<<endl; 
	cout<<"The bear opens its big mouth and eats you."<<endl;
	cout<<"The bear throws your bottom half across the forest."<<endl; 
	cout<<"You die"<<endl;
	cout<<"GAME OVER."<<endl; 
	exit(0);

}
if (choice =='3')
{

	cout<<"You arrive at the bottom of the hole."<<endl; 
	cout<<"There was nothing down there."<<endl; 
	cout<<"You had to climb back up the hole."<<endl; 
	cout<<"Your strength went up!"<<endl; 
	cout<<"You have gained attack points!"<<endl; 
	attack = attack + 10;

}
if (choice =='4')
{

	cout<<"You found gold!"<<endl; 
	cout<<"You found silver! "<<endl; 
	cout<<"You found steel!"<<endl; 
	cout<<"You attach your metals to your shield."<<endl; 
	cout<<"Your shield increases!"<<endl;
       	shield = shield + 10; 	
	
	
}

cout<<"Hit any key to continue...";
cin>>wait; 
cin.ignore(numeric_limits<streamsize>::max(),'\n'); 


} // end of day 4 while loop 
// reset the choice so the code doesn't skip
choice = 'a';

while((choice != '1')&&(choice!='2')&&(choice!='3')&&(choice!='4'))
{


s.b();

cout<<"Day 5"<<endl; 
cout<<"You arrive at the volcano where the dragon lives."<<endl; 
cout<<"What will you do just before the battle?"<<endl; 

cout<<"1.)Collect lava thinking that it might come in handy"<<endl; 
cout<<"2.)Climb the rock wall straight to where the dragon is"<<endl; 
cout<<"3.)Check out the abandoned temple"<<endl; 
cout<<"4.)Just follow the trail that leads to the dragon.(This will take longer)"<<endl; 


cin >> choice; 
cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

s.b();


	if (choice =='1')
	{	

		cout<<"You pour your collected lava onto your shield."<<endl;
	       	cout<<"The lava hardens"<<endl;
		cout<<"You gain shield points!"<<endl;	
		shield = shield + 20;

	}

	if (choice =='2')
	{

		cout<<"Climbing the wall gave you a nice workout!"<<endl;

		cout<<"Your strength and endurance goes up!"<<endl; 

		cout<<"You gain attack points!"<<endl;
	       		attack = attack +20;

	}
	if (choice =='3')
	{
		 dice = rand();
		 dice = dice%100; 
		if (dice < 5){
			cout<<"You found a wand at the temple!"<<endl;
			cout<<"You have attained a magic wand!\nDragon slayer's wand";
		      New_magic = 6;	
		}
		else if((dice>=5) && (dice<24)){
			cout<<"You gave a chant at the temple."<<endl; 
			cout<<"The temple glows and starts to move!"<<endl;
			cout<<"A cannon comes out and blasts a beam of light at you"<<endl;
			cout<<"You are blinded!"<<endl;
			cout<<"[white out]"<<endl;
			cout<<"You've learned the magic of heal!"<<endl;
			New_magic = 1;
			// uses the healing magic. 
		}


		else if((dice>=24) && (dice<43)){
			cout<<"You see a button at the temple"<<endl;
			cout<<"You press it."<<endl;
		        cout<<"After a silence if 5 seconds you hear gears turning."<< endl; 
			cout<<"Spikes come out of the ground and walls of the temple"<<endl;
			cout<<"You run."<<endl;
		       	cout<<"You are hit by one of the spikes!"<<endl;
			cout<<"Your vison blurs and you fall unconscious."<<endl;
			cout<<"You learned the magic of poison!"<<endl;	
			New_magic = 2; 	
	
		}

	
		else if((dice>=43) && (dice<62)){
			cout<<"You arrive at the temple."<<endl; 

		
			cout<<"You see some stones."<<endl; 
			cout<<"They look misaligned."<<endl; 

			cout<<"So you align the stones."<<endl; 

			cout<<"Light shines through the cracks of the temple."<<endl; 


			cout<<"The ground shakes"<<endl; 
			cout<<"When you look around you see trees growing fast"<<endl; 
			cout<<"Some trees are rotting right before your eyes"<<endl; 
			cout<<"You see a squirrel run back wards."<<endl;
			cout<<"Time seem to speed in one area and reverse in another."<<endl; 
			cout<<"You've gained the time magic!\n!"<<endl;  
			New_magic = 3; 

		}
		else if((dice>=62) && (dice<81)){
			
		cout<<"You walk around to check out the temple."<<endl; 
	
	 	cout<<"Suddently, the ground opens and you fall in"<<endl;
		cout<<"You see a roap."<<endl; 
		cout<<"You pull the roap."<<endl;
		cout<<"you hear a explosion at a distance."<<endl;
	
		cout<<"You hear low roaring sounds"<<endl;
		cout<<"The sound was from an avalanche."<<endl; 
		cout<<"You rush up the walls"<<endl; 
		cout<<"But it was too late snow rushes in the hole"<<endl; 

		cout<<"You get buried alive."<<endl; 

	
		cout<<"[black out]"<<endl; 
	
		cout<<"You have attained the ice magic!"<<endl; 


			New_magic = 4; 


		}
		else if((dice>=81) && (dice<100)){
			cout<<"You arrive at the temple."<<endl;
			cout<<"You see a lever in the middle"<<endl;
			cout<<"You decide to pull the lever."<<endl;
			cout<<"Black liquid starts to pour out of the cracks of the temple"<<endl;
			cout<<"Then after a cracking sound the liquid starts to burn."<<endl;
			cout<<"You run towards where you came from"<<endl;
			cout<<"But the fire is already all over the temple."<<endl;
			cout<<"The fire loosens the vines on the stone."<<endl;
			cout<<"The stone falls and blocks your way. You are trapped!"<<endl;
			cout<<"You are surrounded by fire"<<endl;
			cout<<"The fire touches you"<<endl;
			cout<<"The fire does not feel hot."<<endl; 
			cout<<"You walk through the fire to escape the temple."<<endl; 
			cout<<"You gained the magic of fire!"<<endl; 

			New_magic = 5; 
		}

		if(magic != 0)
		{
			cout<<"You already have a magic.\n"<<endl;
	
			cout<<"1.)I want my new magic! Replace it with my old magic"<<endl;
		       	cout<<"2.)I want to keep my old magic. Don't replace my old magic"<<endl;
			cin>>choice;
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

			if (choice == '1')
			{
				magic  = New_magic;
			}	
			else if (choice =='2')
			{
				cout<<"You kept your old magic."<<endl;
			}
			else 
			{
				cout<<"Your old magic has been kept."<<endl;
			}
		}
		else
		{
			magic = New_magic;
		}





	

	}
	if (choice =='4')
	{

		cout<<"You slowly climbed up the mountain"<<endl;

		cout<<"You saved your evergy for the battle\nYou also had time to eat a quick meal"<<endl;

		cout<<"You gained some health points"<<endl; 
		hp.health = hp.health +20;
	}

cout<<"Hit a key to continue...";
cin>>wait;
cin.ignore(numeric_limits<streamsize>::max(),'\n'); 



} // end of day 5 while loop. 


s.b();



int battle=1; 
while (battle == 1)
{
// Thawing chance 
	if (freeze ==1)
	{
		dice = rand();
		dice = dice%6;
		if (dice == 0)
		{
			cout <<"The dragon is thawed!"<<endl;
			freeze = 0; 

		}
		else 
		{
			cout<<"The dragon is frozen!"<<endl; 
		}
	}

	if (turn==1)
	{
		cout<<"You arrive at the dragon!"<<endl; 
		cout<<"The fight beggins!"<<endl; 
		cout<<"What will you do?"<<endl;
		turn++;
	}	
	else
	{

		cout<<"Your health is "<<hp.health<<endl; 

		cout<<"What will you do next?"<<endl;
	}
	cout<<"1.)Attack "<<endl; 
	cout<<"2.)Defend"<<endl; 
	cout<<"3.)Attemp a dodge"<<endl; 
	cout<<"4.)Use your magic" <<endl; 
	cout<<"5.)Eat food to heal"<<endl; 
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

// 	clear screen 

s.b();




	if (choice == '1')
	{
	
		cout<<"You attack the dragon!"<<endl; 

		cout<<"The dragon takes "<<attack<<" damage!"<<endl;
		DH.health = DH.health - attack; 
		cout<<"The dragon's Health is "<<DH.health<<endl; 

		if (freeze ==1)
		{

			cout<<"The dragon is frozen!"<<endl; 
		}
		else
		{
			if (DH.health<=0)
			{

			}
			else
			{
				cout<<"The dragon attacks you!"<<endl; 
				cout<<"You suffer "<<DA<<" damage!"<<endl; 
				hp.health = hp.health - DA;
			}

		}







	}
	if (choice == '2')
	{

		if (freeze ==1)
		{
			
			cout<<"The dragon is still frozen!"<<endl; 
		}	
		else 
		{

			cout<<"You defend!"<<endl; 
			cout<<"The dragon attacks!"<<endl;
	        	damage = DA - shield;	
			if (damage <= 0)
			{
				cout<<"You suffer 0 damage!"<<endl;
			}
			else 
			{
				cout<<"You suffer "<<damage<<"damage!"<<endl; 
				cout<<"Your health is"<< hp.health<<endl; 
				cout<<""<<endl; 
				cout<<""<<endl; 
				cout<<""<<endl;
			}	
		}






	}
	if (choice == '3')
	{
		if (freeze==1)
		{

			cout<<"The dragon is frozen!"<<endl; 
		}
		else 
		{
		
			cout<<"You attempt a dodge!"<<endl;
	       		dice = rand();
			dice = dice%4;
			if (Dice==0)
			{
				cout<<"You failed to dodge the dragon's attack!"<<endl;
			       cout<<"You suffer "<<DA<<" damage!"<<endl;
			       hp.health = hp.health - DA;
				if (hp.health <= 0)
			 	{
					battle = 0; 

				}
       				else 
				{
				}
			}	
			else 
	 		{
				cout<<"Dodge sucesssful!"<<endl;
			}			
	       			       
			
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
		
		}








	}
	if (choice == '4')
	{
		

		cout<<"You use your magic!"<<endl; 

		if (magic ==1)
		{
			cout<<"You used your heal magic!"<<endl; 
			cout<<"You heal 20 health!"<<endl;
		       	hp.health = hp.health + 20; 	
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 		
		}
		else if (magic ==2)
		{
			cout<<"You used your poison magic"<<endl; 
			cout<<"The dragon is poisoned!"<<endl;
			DH.health = DH.health - 5; 
		       	magic_on = 1;
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
		}

		else if (magic ==3)
		{
			cout<<"You use your stop time magic!"<<endl;
			dice = rand();
			dice = dice%3;
			if (dice == 0)
			{
				cout<<"Your magic didn't work!"<<endl;
				ST = 0;
			}
				
			else 
			{
				cout<<"time has stopped!"<<endl;
				ST = 1;
			}
			cout<<""<<endl; 
			cout<<""<<endl; 
		}
		else if (magic ==4)
		{
			if (freeze ==1)
			{
				cout<<"The Dragon is already frozen!"<<endl;
			}
			else
			{
				cout<<"You used your freeze magic!"<<endl; 
				dice = rand(); 
				dice = dice%3; 
				if (dice==0)
				{
					freeze =1; 
					cout<<"The dragon froze!"<<endl;
				}
				else 
				{
						cout<<"The dragon did not freeze!"<<endl;
				}
				cout<<""<<endl; 
				cout<<""<<endl; 
				cout<<""<<endl; 
				cout<<""<<endl; 
			} 
		}
		else if (magic ==5)
		{
			cout<<"You used your fire magic!"<<endl; 
			cout<<"The dragon burned!"<<endl; 
			DH.health = DH.health -10; 
			magic_on = 1; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
		}

		else if (magic ==6)
		{
			cout<<"You use the dragon slayers wand!"<<endl; 
			cout<<"Zaaaaaaaaaap!"<<endl; 
			cout<<"The dragon was defeated!"<<endl; 
			cout<<""<<endl; 
			DH.health = 0; 
			DH.health = DH.health - (DH.health*2);
			cout<<""<<endl; 
			cout<<""<<endl; 
		}
		else 
		{
			hp.health = hp.health +10;
			cout<<"Default magic used!"<<endl;
			cout <<"You gain 10 health points!"<<endl;
		}
			
		if ( (magic ==3) && (ST ==1))
		{
			cout<<"Time has stopped so the dragon could not attack this round."<<endl;
			// unstop time 
			ST = 0; 
		}
		else if ( (magic ==4)&&(freeze==1) )
		{
			cout<<"The dragon is frozen!"<<endl;
		}
		else
		{



			cout<<"The dragon attacks!"<<endl; 
			cout<<"You suffer "<<DA<<" damage!"<<endl; 
			hp.health = hp.health -DA; 
			cout<<""<<endl; 

			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
		}






	}
	else if (choice == '5')
	{

		if (freeze==1)
		{
			
			cout<<"You eat food!"<<endl; 

			cout<<"You recover some health points!"<<endl; 

			hp.health = hp.health +10; 
		}	
		else 
		{


			cout<<"You eat food!"<<endl; 

			cout<<"You recover some health points!"<<endl; 

			hp.health = hp.health +10; 
			cout<<"The dragon attacks!"<<endl; 
			cout<<"You suffer "<<DA<<" damage!"<<endl; 
			cout<<""<<endl; 
			hp.health = hp.health - DA; 
			cout<<""<<endl; 
			cout<<""<<endl; 
			cout<<""<<endl; 
		}






	}

	// additive magic 
	if (magic_on == 1)
	{
		if (magic ==2)
		{
			PD = PD + 5;
			DH.health = DH.health - PD;
			cout<<"The dragon is suffering from poison damage"<<endl;
			cout<<"The dragon's health is "<<DH.health<<endl;	
		}
		else if (magic == 5)
		{
			cout<<"The dragon is on fire and is suffering from the fire."<<endl;
			DH.health = DH.health - 5;
			cout<<"The dragon's health is "<<DH.health<<endl;	

		}
		else 
		{

			cout<<"Error in additive magic."<<endl; 
		}
	}
	else 
	{
	}
	if ( DH.health<= 0)
	{
		battle = 2; 
		cout<<"The dragon has been defeated!"<<endl;
	}
	else 
	{
	}
	if (hp.health <= 0)
	{
		battle = 0; 
	}
	else 
	{
	}

}
// end of battle 

if (battle == 0)
{
	cout<<"You lost!"<<endl;
	// you lost 
}

else if (battle == 2)
{

	cout<<"You won! congratulations!"<<endl;
	//you won!
}

}

