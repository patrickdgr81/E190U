#Experimental Design
##Accuracy Test
The first I'm using is to determine the accuracy of firing for Cube2. In theory, a better controller will be easier to use and the player should therefore be more accurate in the game. To test this, in the shotevent process, I write out to file a declaration that the player fired and another line if he does damage. To keep track of which player is which, I write out everything that is not a bot, since keeping track of bot shooting is not indivicative on player or controller perforamnce.

<pre><code>
if (strcmp(playerName,"bot") != 0) {
	   fprintf(accuracyTest, "Player %s fired!\n", playerName);
	}
</code></pre>
