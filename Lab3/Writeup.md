#Experimental Design
##Accuracy Test
The first I'm using is to determine the accuracy of firing for Cube2. In theory, a better controller will be easier to use and the player should therefore be more accurate in the game. To test this, in the shotevent process, I write out to file a declaration that the player fired and another line if he does damage. To keep track of which player is which, I write out everything that is not a bot, since keeping track of bot shooting is not indivicative on player or controller perforamnce.

<pre><code>
if (strcmp(playerName,"bot") != 0) {
	   fprintf(accuracyTest, "Player %s fired!\n", playerName);
	}
accuracyTest = fopen("accuracyTest.txt","w");
deathTest = fopen("deathTest.txt","w");
        if ((accuracyTest == NULL)||deathTest == NULL) {
	  printf("Error opening file !\n");
	  exit(1);
	}
</code></pre>

To measure this, I count the number of total shots in the file and the total number of shots that did damage. Then divide one over the other to find the accuracy percentage.

##Death Test
This is very straightforward, everytime you die, I write out to file that you did so.

<pre><code>
if(ts.health<=0)
        {
	    char* playerName = target->name;
	    if (strcmp(playerName,"bot") != 0) {
	      fprintf(deathTest, "Player %s died!\n", playerName);
	    }
</code></pre>
In theory, a better controller will allow you to manuer the joysticks and bottons more comfortably and should therefore die less.
