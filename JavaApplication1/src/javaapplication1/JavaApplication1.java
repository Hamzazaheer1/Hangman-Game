package javaapplication1;
import java.util.Random;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author hamza
 */


public class JavaApplication1 {
    
    //Get a random number to get the word, it depends on the chosen level
    static int RandomNumber() {
        int min = 1;
        int max = 5;

	Random random = new Random();

	int value = random.nextInt(max + min) + min;
	return value;
    }
    
    // Get a random word from the wordlist depending on the level chosen
    static String RandomWord() {
        
        int random_number = RandomNumber();
	int counter = 0;
        String word = null;
        
        File myFile = new File("C:\\Users\\hamza\\Desktop\\wordlist.txt");
        try { 
            Scanner sc = new Scanner(myFile);
            while(sc.hasNextLine()){
                String line = sc.nextLine();
                if(random_number == counter)
                {
                    word = line;
                    break;
                }
                counter++;
            }
            sc.close();
        } catch (FileNotFoundException ex) {
             ex.printStackTrace();
        }
        return word;      
    }
    
    //Print chosen right letters or '-'
    static int PrintWord(String word, String letter) {
        for (int x = 0; x < word.length(); x++) {
            if (letter.contains(String.valueOf(word.charAt(x))))
                System.out.println(word.charAt(x));
            else {
                System.out.println("_ ");
            }
        }
        return 0;
    }
    
    //Design the hangman depending on lives
    static void Design(int count) {
		if (count == 6) {
			System.out.println("");
			System.out.println();
			System.out.println();
			System.out.println();
			System.out.println();
			System.out.println("___|___");
			System.out.println();
		}
		if (count == 5) {
			System.out.println("Wrong guess, try again");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("___|___");
		}
		if (count == 4) {
			System.out.println("Wrong guess, try again");
			System.out.println("   ____________");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   | ");
			System.out.println("___|___");
		}
		if (count == 3) {
			System.out.println("Wrong guess, try again");
			System.out.println("   ____________");
			System.out.println("   |          _|_");
			System.out.println("   |         /   \\");
			System.out.println("   |        |     |");
			System.out.println("   |         \\_ _/");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("   |");
			System.out.println("___|___");
		}
		if (count == 2) {
			System.out.println("Wrong guess, try again");
			System.out.println("   ____________");
			System.out.println("   |          _|_");
			System.out.println("   |         /   \\");
			System.out.println("   |        |     |");
			System.out.println("   |         \\_ _/");
			System.out.println("   |           |");
			System.out.println("   |           |");
			System.out.println("   |");
			System.out.println("___|___");
		}
		if (count == 1) {
			System.out.println("Wrong guess, try again");
			System.out.println("   ____________");
			System.out.println("   |          _|_");
			System.out.println("   |         /   \\");
			System.out.println("   |        |     |");
			System.out.println("   |         \\_ _/");
			System.out.println("   |           |");
			System.out.println("   |           |");
			System.out.println("   |          / \\ ");
			System.out.println("___|___      /   \\");
		}
		if (count == 0) {
			System.out.println("GAME OVER!");
			System.out.println("   ____________");
			System.out.println("   |          _|_");
			System.out.println("   |         /   \\");
			System.out.println("   |        |     |");
			System.out.println("   |         \\_ _/");
			System.out.println("   |          _|_");
			System.out.println("   |         / | \\");
			System.out.println("   |          / \\ ");
			System.out.println("___|___      /   \\");
			System.out.println("GAME OVER! The word was " + word);
		}
	}
    
    
    
    public static void main(String[] args) {
        int counter1 = 0;
        int live = 6;
        String letter;
        String word; 
        String guessedLetters = "";

        
        word = RandomWord();
        System.out.println(word); //test
        while(live > 0)
        {
            Design(live);
            PrintWord(word, guessedLetters);
            
            if (counter1 == word.length())
			break;
            System.out.println("Enter one letter only once: ");
            System.out.println("Letters guesses: " + guessedLetters);

            Scanner sc= new Scanner(System.in);
            System.out.println("Enter a letter: ");
            letter= sc.nextLine(); 
            
            guessedLetters += letter;
            
            
            if (word.contains(letter) != false)
		{
			counter1 += 1;
			continue;
		}
		else
		{
			live--;
		}    
        }
        
        if (live == 0) //If we have finished our lives
	{
		Design(0);
		System.out.println("GAME OVER! The word was " + word);
	}
	if (live > 0) //If we complete the word correctly
	{
		System.out.println("You Win! The word was " + word);
	}     
    }
    
}