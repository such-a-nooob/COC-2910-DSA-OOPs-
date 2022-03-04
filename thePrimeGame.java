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
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

class primeComposite
{
	private JFrame frame;
	private JPanel panel;
	private JPanel panelN;	//panel to store the number label
	private JPanel panelB;	//panel to store the Prime and Not Prime buttons
	private JPanel panelS;	//panel to store the score labels
	private JPanel panelR;	//panel to store the Reset button
	private JLabel label;
	private JLabel lbNumber;	//label to show a random number
	private JLabel lbScore;	//label to show the score
	private JButton bPrime;	
	private JButton bComposite;
	private JButton bReset;

	private int width;	//width of the frame
	private int height;	//height of the frame
	private int score;	
	private Random r;
    	private int randomNum;

    	//initialising the above mentioned members using constructor
    	public primeComposite(int w, int h)
    	{
    		frame = new JFrame();
    		panel = new JPanel(new GridLayout(4,1,0,30));
    		panelN = new JPanel();
    		panelB = new JPanel(new GridLayout(1,2));
    		panelS = new JPanel();
    		panelR = new JPanel();
		label = new JLabel("SCORE : ");
		lbNumber = new JLabel();
		lbScore = new JLabel();
		bComposite = new JButton("No Prime"); 
		bPrime = new JButton("Prime");
		bReset = new JButton("Reset");
		width = w;
		height = h;
		score = 0;
		r = new Random();
    		randomNum = r.nextInt(100);
    	}

    	//setting up the components in the frame
    	public void setupGUI() 
    	{
    		frame.setSize(width, height);	//setting the size of the frame
		frame.setTitle("The Prime Game");	//setting the title of the frame

		//set the initial text for the Number and Score label
		lbNumber.setText(String.valueOf(randomNum));	
		lbScore.setText(String.valueOf(score));

		//setting the fonts 
		lbNumber.setFont(new Font("Calibri", Font.BOLD, 72));
		lbScore.setFont(new Font("Calibri", Font.BOLD, 18));
		label.setFont(new Font("Calibri", Font.BOLD, 18));
		bComposite.setFont(new Font("Calibri", Font.ITALIC, 16));
		bPrime.setFont(new Font("Calibri", Font.ITALIC, 16));

		//adding Number lebel to the row 1 of the JPanel 'panel' 
		panelN.add(lbNumber);
		panel.add(panelN);

		//adding 'Prime' and 'No Prime' buttons to the row 2 of the JPanel 'panel' 
		/*(adding buttons to the JPanel 'pb' and 'cb' resp. 
		  and then in JPanel 'panelB' to maintain size of the buttons in the grid layout)*/
		JPanel pb = new JPanel();
		pb.add(bPrime);
		panelB.add(pb);	
		//call function 'primeAction' when 'Prime' button is clicked
		bPrime.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent evt) 
			{
				primeAction();
			}
        	});

        	JPanel cb = new JPanel();
		cb.add(bComposite);
		panelB.add(cb);
		//calls function 'compositeAction' when 'No Prime' button is clicked
		bComposite.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent evt) 
			{
				compositeAction();
			}
		});
        	panel.add(panelB);

        	//adding lebels to show the Scores in the row 3 of the JPanel 'panel' 
		panelS.add(label);
		panelS.add(lbScore);
		panel.add(panelS);

		//adding 'Reset' button to the row 4 of the JPanel 'panel' 
		JPanel jp = new JPanel(new GridLayout(1,4));
		jp.add(new JLabel(""));
		jp.add(new JLabel(""));
		jp.add(new JLabel(""));
		jp.add(bReset);
		panelR.add(jp);
		//calls function 'resetAction' when 'Reset' button is clicked
		bReset.addActionListener(new ActionListener() 
		{
        		public void actionPerformed(ActionEvent evt) 
            		{
                		resetAction();
            		}
        	});
		panel.add(panelR);

        	frame.add(panel);	//add the panel to the frame
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//set the frame close operation
		frame.setVisible(true);	//set the visibility to true to display the components in the frame
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
			randomNum = r.nextInt(100);	//generate the next random number
			lbNumber.setText(String.valueOf(randomNum)); //set the random number in the 'Number' label
		}
		else //(Answer is incorrect)
		{
			JOptionPane.showMessageDialog(frame, "GAME OVER!\nYour Score : "+score);	//show a Message dialog box with scores
			resetAction();	//reset the game
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
			randomNum = r.nextInt(100);
			lbNumber.setText(String.valueOf(randomNum)); 
		}
		else	//(Answer is incorrect)
		{
			JOptionPane.showMessageDialog(frame, "GAME OVER!\nYour Score : "+score);
			resetAction();
		}
	}

	//Operations to be performed when 'Reset' button is clicked
	//Resets the Game
	public void resetAction()
	{
		score = 0;	//set the score to 0
		lbScore.setText(String.valueOf(score));	//show the new score
		randomNum = r.nextInt(100);	//generate a new random number
		lbNumber.setText(String.valueOf(randomNum));	//set the random number in the 'Number' label
	}	
}

public class thePrimeGame {
	public static void main(String[] args) { 
		primeComposite mygame = new primeComposite (320, 370); 
		mygame.setupGUI();
}
}
