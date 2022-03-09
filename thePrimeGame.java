/*
COC2030 ASSIGNMENT
--Create a Graphical-User-Interface (GUI) in Java--
	1. Create a GUI of your choice in Java.
	2. It should include a window (frame and panel) and some components.
	3. Try to incorporate event handling by creating an event source and listeners.
	4. Try to write comments for each component (to explain its purpose and action for the related events)
	5. Upload source code and screenshots of your program.


Name : Muniba Rahman
Faculty no. : 20COB275
Sr no. : A2CO-36

*/

import java.util.*;
import javax.swing.*;
import java.awt.*; //import all of the java.awt classes but does not import classes under java.awt.event
import java.awt.event.*;

class primeComposite
{
	private JFrame frame;
	private JPanel panel;
	private JPanel numPanel;	//panel to store the random number number
	private JLabel label;
	private JLabel lbNumber;	//label to show a random number
	private JLabel lbScore;	//label to show the score
	private JButton bPrime;	
	private JButton bComposite;
	private JButton bEndGame;

	private int width;	//width of the frame
	private int height;	//height of the frame
	private int score;	
	private Random r;
	private int randomNum;

	//initialising the above mentioned members using constructor
	public primeComposite(int w, int h)
	{
		frame = new JFrame();
		panel = new JPanel();
		numPanel = new JPanel();
		label = new JLabel("SCORE : ");
		lbNumber = new JLabel();
		lbScore = new JLabel();
		bComposite = new JButton("No Prime"); 
		bPrime = new JButton("Prime");
		bEndGame = new JButton("End Game");
		width = w;
		height = h;
		score = 0;
		r = new Random();
		randomNum = r.nextInt(350);
	}

	//setting up the components in the frame
	public void setupGUI() 
	{
		frame.setSize(width, height);	//sets the size of the frame
		frame.setTitle("The Prime Game");	//sets the title of the frame


		//removing the default layout for JPanel 'panel' 
		//so that we can customize the size and location of each component on our choice
		panel.setLayout(null);	

		
		//setting Number lebel in the panel

		lbNumber.setFont(new Font("Calibri", Font.BOLD, 75));	//sets font of the random number
		lbNumber.setText(String.valueOf(randomNum));	//sets an initial random number to display 
		numPanel.setSize(320,90);	//sets the size of the number panel
		numPanel.setLocation(-1,25);	//sets the location(co-ordinates) of the number panel
		numPanel.add(lbNumber);	
		panel.add(numPanel);	//adds the number panel to the main panel
		

		//setting 'Prime' and 'No Prime' buttons in the panel 

		bPrime.setFont(new Font("Calibri", Font.ITALIC, 16));	//sets font of the text on the button 'Prime'
		bPrime.setSize(100, 30);	//sets the size of the 'Prime' button
		bPrime.setLocation(30, 130);	//sets the location(co-ordinates) of the 'Prime' button
		panel.add(bPrime);	//adds the 'Prime' button to the panel

		//calls function 'primeAction' when 'Prime' button is clicked
		bPrime.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent evt) 
			{
				primeAction();
			}
		});

		bComposite.setFont(new Font("Calibri", Font.ITALIC, 16));	//sets font of the text on the button 'No Prime'
		bComposite.setSize(100, 30);	//sets the size of the 'No Prime' button
		bComposite.setLocation(175, 130);	//sets the location(co-ordinates) of the 'No Prime' button
		panel.add(bComposite);	//adds the 'No Prime' button to the panel

		//calls function 'compositeAction' when 'No Prime' button is clicked
		bComposite.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent evt) 
			{
				compositeAction();
			}
		});
		

		//setting lebels to show the Scores in the panel

		label.setFont(new Font("Calibri", Font.BOLD, 17));	
		label.setSize(120, 30);	
		label.setLocation(105, 190);
		panel.add(label);

		lbScore.setFont(new Font("Calibri", Font.BOLD, 17));	//sets font of the Score label
		lbScore.setSize(120, 30);	//sets the size of the the Score label
		lbScore.setLocation(185, 190);	//sets the location(co-ordinates) of the Score label
		lbScore.setText(String.valueOf(score));	//sets the initial text for the Score label
		panel.add(lbScore);	//adds the Score label to the panel


		//setting 'EndGame' button in the panel

		bEndGame.setFont(new Font("Calibri",0, 13));
		bEndGame.setSize(90, 28);
		bEndGame.setLocation(190, 280);
		panel.add(bEndGame);
		//calls function 'endGameAction' when 'EndGame' button is clicked
		bEndGame.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent evt) 
			{
				endGameAction();
			}
		});
		
		frame.add(panel);	//adds panel to the frame 
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//sets the frame close operation
		frame.setVisible(true);	//sets the visibility to true to display the components in the frame
	}

	//Operations to be performed when 'Prime' button is clicked
	public void primeAction()
	{
		int num = Integer.parseInt(lbNumber.getText());	//get the random number and convert to int to check prime
		//checking if 'num' is prime
		int flag = 0;
		for(int i=2; i<num; i++)
		{
			if(num%i == 0) 
			{
				flag=1;
				break;
			}
		}
		if(flag==0)	//if the number is prime (Answer is correct)
		{
			score+=1;	//increment the score
			lbScore.setText(String.valueOf(score)); //show the new score
			randomNum = r.nextInt(350);	//generate the next random number
			lbNumber.setText(String.valueOf(randomNum)); //set the random number in the 'Number' label
		}
		else //(Answer is incorrect)
		{
			endGameAction();	//end the game
		}
	}

	//Operations to be performed when 'No Prime' button is clicked
	public void compositeAction()
	{
		int num = Integer.parseInt(lbNumber.getText());
		int flag = 0;
		for(int i=2; i<num; i++)
		{
			if(num%i == 0) 
			{
				flag=1;
				break;
			}
		}
		if(flag==1)	//if number is NOT prime (Answer is correct)
		{
			score+=1;
			lbScore.setText(String.valueOf(score)); 
			randomNum = r.nextInt(350);
			lbNumber.setText(String.valueOf(randomNum)); 
		}
		else	//(Answer is incorrect)
		{
			endGameAction();
		}
	}

	//Operations to be performed when 'EndGame' button is clicked
	//end the Game
	public void endGameAction()
	{
		JOptionPane.showMessageDialog(frame, "GAME OVER!\nYour Score : "+score);	//show a Message dialog box with scores
		score = 0;	//set the score to 0
		lbScore.setText(String.valueOf(score));	//show the new score
		randomNum = r.nextInt(350);	//generate a new random number
		lbNumber.setText(String.valueOf(randomNum));	//set the random number in the 'Number' label
	}	
}

public class thePrimeGame {
	public static void main(String[] args) { 
		primeComposite mygame = new primeComposite (320, 370); 
		mygame.setupGUI();
}
}
