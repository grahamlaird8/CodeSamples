/**
  *@file: TicTacToe.java
  *		Program creates a game of TicTacToe
  *		made for 2 users, implemented with GUIs
  *
  *@due: 02/22/19, extended to 02/24/19
  *@authors Graham Laird & Finnian Allen
  */


//package tictactoe;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TicTacToe extends JFrame {

	/**
	 *initialize all variables used throughout the GUI
	 */
	
	private JButton button1;    // Top left button
	private JButton button2;    // Top center button
	private JButton button3;    // Top right button
	private JButton button4;    // Middle left button
	private JButton button5;    // Middle center button
	private JButton button6;    // Middle right button
	private JButton button7;    // Bottom left button
	private JButton button8;    // Bottom center button
	private JButton button9;    // Bottom right button
	private JButton newGameButton; // button to start new game
	private JButton resetButton; //button to reset game
	private JButton exitButton; //button to exit program
	private JTextField player1;    // player 1 name field
	private JTextField player2;    // player 1 name field
	private JPanel panel;       // A panel to hold 9 TicTactoe button components
	private JPanel playerPanel; // panel to hold all player info
	private JPanel player1Panel; // panel to hold player1 info
	private JPanel player2Panel; // panel to hold player 2 info
	private JPanel bottomPanel; // panel to hold bottom buttons and status bar
	private JPanel buttonPanel; // panel to hold bottom buttons
	
	private JLabel statusLabel;	//status bar
	private JLabel player1Losses; //player1 losser
	private JLabel player1Wins; //player1 wins
	private int player1WinCount = 0; //# of player1 wins
	private int player1LossCount = 0; //#of player2 wins

	private JLabel winsLabel1; // Wins label
	private JLabel lossesLabel1; // Losses label
	private JLabel winsLabel2; // Wins label
	private JLabel lossesLabel2; // Losses label
	private JLabel player2Losses; // player2 losses
	private JLabel player2Wins; //player2 wins
	private int player2WinCount = 0; //#of player2 wins
	private int player2LossCount = 0; //#of player1 wins
	
	private JLabel name; //player1 name
	private JLabel name2; //player2 name
	private final int WINDOW_WIDTH = 500; // Window width
	private final int WINDOW_HEIGHT = 500; // Window height
	private String player1Name; // player 1's name
	private String player2Name; // player 2's name
	
	//bools to keep track if each botton has been checkIfGameOver
	private Boolean checked1 = false;
	private Boolean checked2 = false;
	private Boolean checked3 = false;
	private Boolean checked4 = false;
	private Boolean checked5 = false;
	private Boolean checked6 = false;
	private Boolean checked7 = false;
	private Boolean checked8 = false;
	private Boolean checked9 = false;
	
	//bools to keep track of WHO checkIfGameOver each button 
	private Boolean button1Player1 = false;
	private Boolean button2Player1 = false;
	private Boolean button3Player1 = false;
	private Boolean button4Player1 = false;
	private Boolean button5Player1 = false;
	private Boolean button6Player1 = false;
	private Boolean button7Player1 = false;
	private Boolean button8Player1 = false;
	private Boolean button9Player1 = false;
	private Boolean button1Player2 = false;
	private Boolean button2Player2 = false;
	private Boolean button3Player2 = false;
	private Boolean button4Player2 = false;
	private Boolean button5Player2 = false;
	private Boolean button6Player2 = false;
	private Boolean button7Player2 = false;
	private Boolean button8Player2 = false;
	private Boolean button9Player2 = false;
	
	//bool to keep track of in-game status
	private Boolean inGame = false;
	
	//bool to keep track of whos turn it is
	private Boolean player1Turn = true; 
   
	public TicTacToe()
	{
		// Set the title bar text.
		setTitle("Tic-Tac-Toe");

		// Set the size of the window.
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);

		// Specify what happens when the close button is clicked.
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//initialize the player infos
		initializePlayerInfo();
		
		//build the middle panel to hold the TicTacToe buttons
		buildMiddlePanel();
		
		//build the panel to hold player info
		buildPlayerPanel();
		
		//build bottom panel to hold 3 status buttons and status bar
		buildBottomPanel();
      
		// Add the info to the window
		add(panel, BorderLayout.CENTER);
		add(playerPanel, BorderLayout.NORTH); // adds the two player panels
		add(bottomPanel, BorderLayout.SOUTH);
			  
		// Display the window.
		setVisible(true);   
	}	
	
	
	/**
      The initializePlayerInfo method initializes all of the player info to the initial states
   */
	private void initializePlayerInfo()
	{
		//initialize player info labels
		player1 = new JTextField("Player 1", 8); 
		player2 = new JTextField("Player 2", 8);
		winsLabel1 = new JLabel("Wins:"); 
		lossesLabel1 = new JLabel("Losses:");
		winsLabel2 = new JLabel("Wins:");
		lossesLabel2 = new JLabel("Losses:");
		player1Wins = new JLabel("0");
		player2Wins = new JLabel("0");
		player1Losses = new JLabel("0");
		player2Losses = new JLabel("0");
		name = new JLabel("Name: ");
		name2 = new JLabel("Name: ");
		statusLabel = new JLabel("Welcome to Tic-Tac-Toe!");
	}
	
	/**
		The buildMiddlePanel method builds the TicTacToe button panel.
	*/
	private void buildMiddlePanel()
	{
		//build the 9 TicTacToe buttons
		buildButtons();
		
		panel = new JPanel();
		panel.setLayout(new GridLayout(3, 3));
		panel.add(button1);
		panel.add(button2);
		panel.add(button3);
		panel.add(button4);
		panel.add(button5);
		panel.add(button6);
		panel.add(button7);
		panel.add(button8);
		panel.add(button9);     
	}
   
	/**
		The buildButtons method builds 9 TicTacToe buttons 
	*/
	private void buildButtons()
	{
		button1 = new JButton();
		button2 = new JButton();
		button3 = new JButton();
		button4 = new JButton();
		button5 = new JButton();
		button6 = new JButton();
		button7 = new JButton();
		button8 = new JButton();
		button9 = new JButton(); 
   
		button1.addActionListener(new ButtonListener());
		button2.addActionListener(new ButtonListener());
		button3.addActionListener(new ButtonListener());
		button4.addActionListener(new ButtonListener());
		button5.addActionListener(new ButtonListener());
		button6.addActionListener(new ButtonListener());
		button7.addActionListener(new ButtonListener());
		button8.addActionListener(new ButtonListener());
		button9.addActionListener(new ButtonListener());
	}
   
   
	/**
		The buildBottomPanel method builds the bottom button panel.
	*/
	private void buildBottomPanel()
	{
		bottomPanel = new JPanel();
		bottomPanel.setLayout(new BorderLayout());
		statusLabel.setBorder(BorderFactory.createEtchedBorder(1));
       
		buildButtonPanel();
		bottomPanel.add(buttonPanel);
		bottomPanel.add(statusLabel, BorderLayout.SOUTH); 	
	}
   
	/**
		The buildBottomPanel method builds the panel with the 3 buttons on the bottom.
	*/
	private void buildButtonPanel(){
		buttonPanel = new JPanel();
       
		newGameButton = new JButton("New Game");
		resetButton = new JButton("Reset");
		exitButton = new JButton("Exit");
		newGameButton.addActionListener(new ButtonListener());
		resetButton.addActionListener(new ButtonListener());
		exitButton.addActionListener(new ButtonListener());
		
		buttonPanel.add(newGameButton);
		buttonPanel.add(resetButton);
		buttonPanel.add(exitButton);
	}
   
	/**
		The resetGame method resets the game state to as if the program has just been opened
	*/
	private void resetGame()
	{
		resetBoard();
       
		statusLabel.setText("Welcome to Tic-Tac-Toe!");
		player1.setEditable(true);
		player2.setEditable(true);
		player1WinCount = 0;
		player2LossCount = 0;
		player1Wins.setText("" + player1WinCount);
		player2Losses.setText("" + player2LossCount);
		player2WinCount = 0;
		player1LossCount = 0;
		player2Wins.setText("" + player1WinCount);
		player1Losses.setText("" + player2LossCount);
       
		player1.setText("Player 1");
		player2.setText("Player 2");
       
		inGame = false;
	}
   
	/**
		The resetBoard method resets the board after a single game has been won/stalemated
	*/
	private void resetBoard()
	{
		button1.setIcon(null);
		button2.setIcon(null);
		button3.setIcon(null);
		button4.setIcon(null);
		button5.setIcon(null);
		button6.setIcon(null);
		button7.setIcon(null);
		button8.setIcon(null);
		button9.setIcon(null);
		
		button1Player1 = false;
		button2Player1 = false;
		button3Player1 = false;
		button4Player1 = false;
		button5Player1 = false;
		button6Player1 = false;
		button7Player1 = false;
		button8Player1 = false;
		button9Player1 = false;
		button1Player2 = false;
		button2Player2 = false;
		button3Player2 = false;
		button4Player2 = false;
		button5Player2 = false;
		button6Player2 = false;
		button7Player2 = false;
		button8Player2 = false;
		button9Player2 = false;
		
		checked1 = false;
		checked2 = false;
		checked3 = false;
		checked4 = false;
		checked5 = false;
		checked6 = false;
		checked7 = false;
		checked8 = false;
		checked9 = false;
		
		player1Turn = true;
	}
   
	/**
		The buildPlayerPanel method puts together the player info panel
	*/
	private void buildPlayerPanel()
	{
		playerPanel = new JPanel();
        buildPlayerOne();
        buildPlayerTwo();
        playerPanel.add(player1Panel);
        playerPanel.add(player2Panel);
      
	}
   
	/**
		The buildPlayerOne method builds the player1 info panel
	*/
	private void buildPlayerOne()
	{
		player1Panel = new JPanel();
        player1Panel.setBorder(BorderFactory.createTitledBorder("Player 1 (Puppies)"));
        player1Panel.setLayout(new GridLayout(3, 2));
        player1Panel.add(name);
        player1Panel.add(player1);
        player1Panel.add(winsLabel1);
        player1Panel.add(player1Wins);
        player1Panel.add(lossesLabel1);
        player1Panel.add(player1Losses);    
	}
   
	/**
		The buildPlayerTwo method builds the player2 info panel
	*/
	private void buildPlayerTwo()
	{
		player2Panel = new JPanel();
        player2Panel.setBorder(BorderFactory.createTitledBorder("Player 2 (Kittens)"));
        player2Panel.setLayout(new GridLayout(3, 2));
        player2Panel.add(name2);
        player2Panel.add(player2);
        player2Panel.add(winsLabel2);
        player2Panel.add(player2Wins);
        player2Panel.add(lossesLabel2);
        player2Panel.add(player2Losses);  
   
	}  
   
	/**
      Private inner class that handles the event when
      the user clicks a button in the program
	*/
	private class ButtonListener implements ActionListener
	{
                @Override
		public void actionPerformed(ActionEvent e)
		{
			String actionCommand = e.getActionCommand();
			switch (actionCommand) {
				//If the user hits the "New Game" button
				case "New Game":
					//get the entered player names
					player1Name = player1.getText();
					player2Name = player2.getText();
					
					
					if(player1Name.equals("") || player2Name.equals("")) //if either of the names is empty, display an error
					{
						JOptionPane.showMessageDialog(null, "Both names must be entered to start the game!", "ERROR", JOptionPane.ERROR_MESSAGE);
					}
					else //else make the name fields non editable and set the game to start
					{
						player1.setEditable(false);
						player2.setEditable(false);
						inGame = true;
						statusLabel.setText(player1Name + "'s turn");
					}   break;
				//if the user hits the "Reset" button
				case "Reset":
					//confirm that they want to reset the game
					int confirm = JOptionPane.showConfirmDialog(null, "This will end the game and set the win/loss stats to 0. Are you sure?", "ARE YOU SURE?", JOptionPane.YES_NO_OPTION);
					if(confirm == JOptionPane.YES_OPTION) //reset the game if they want to 
					{
						resetGame();
					}   break;
				//if the user hits the "Exit" button
				case "Exit":
					//exit the program
					System.exit(0);
				//else if the user hits one of the TicTacToe buttons
				default:
					if(player1Turn) //if it's player 1s turn
					{
						//run through turn logic
						turn(e, player1Turn);
					}
					else //else if it's player 2s turn
					{
						//run through turn logic
						turn(e, player1Turn); 
					}   break;
			}
		}
	}
	
	/**
		winner method updates all necessary info when someone wins and resets the board
	*/
	private void winner(int player)
	{
		if(player == 1){
			player1WinCount++;
			player2LossCount++;
			player1Wins.setText("" + player1WinCount);
			player2Losses.setText("" + player2LossCount);
			JOptionPane.showMessageDialog(null, player1Name + " has gotten 3 in a row!");
			resetBoard();
		}
		else if(player == 2){
			player2WinCount++;
			player1LossCount++;
			player2Wins.setText("" + player2WinCount);
			player1Losses.setText("" + player1LossCount); 
			JOptionPane.showMessageDialog(null, player2Name + " has gotten 3 in a row!");
			resetBoard(); 
		}
	}
   
	/**
		checkIfGameOver method goes through all possible scenarios where the game would end to see if the game ended on the last move
	*/
	public void checkIfGameOver()
	{
		if (checked1 && checked5 && checked9)
		{ // diagonal from top left to bottom right
			if(button1Player1 && button5Player1 && button9Player1){ //if player 1 got this
                winner(1);
			} 
			else if (button1Player2 && button5Player2 && button9Player2) //else if player 2 got this
			{
                winner(2);
			}     
		}
		if (checked3 && checked5 && checked7)
		{ // diagonal from top right to bottom left
			if(button3Player1 && button5Player1 && button7Player1){
                winner(1);
			} 
			else if (button3Player2 && button5Player2 && button7Player2)
			{
                winner(2);
			}
		}
		if (checked1 && checked4 && checked7)
		{ // vertical from tope left
			if(button1Player1 && button4Player1 && button7Player1){
                winner(1);
			} 
			else if (button1Player2 && button4Player2 && button7Player2)
			{
                winner(2);
			}
		}
		if (checked2 && checked5 && checked8)
		{ // vertical from top middle
            if(button2Player1 && button5Player1 && button8Player1){
                winner(1);
			} 
			else if (button2Player2 && button5Player2 && button8Player2)
			{
                winner(2);
			}
		}
		if (checked3 && checked6 && checked9)
		{ // vertical from top right
			if(button3Player1 && button6Player1 && button9Player1)
			{
                winner(1);
			} 	
			else if (button3Player2 && button6Player2 && button9Player2)
			{
                winner(2);
			}
		}
		if(checked1 && checked2 && checked3) 
		{ // horizontal from top left
			if(button1Player1 && button2Player1 && button3Player1)	
			{
                winner(1);      
			} 
			else if(button1Player2 && button2Player2 && button3Player2)
			{
                winner(2);
			}
		}
		if(checked4 && checked5 && checked6) 
		{ // horizontal from middle left
			if(button4Player1 && button5Player1 && button6Player1)
			{
                winner(1);
			} 
			else if (button4Player2 && button5Player2 && button6Player2)
			{
                winner(2);
			}
		}
		if(checked7 && checked8 && checked9) 
		{ // horizontal from bottom left
			if(button7Player1 && button8Player1 && button9Player1)
			{
                winner(1);
			} 
			else if (button7Player2 && button8Player2 && button9Player2)
			{
                winner(2);
			}
		}
		if(checked1 && checked2 && checked3 && checked4 && checked5 && checked6 && checked7 && checked8 && checked9){ //else if all 9 buttons are presses and no one got 3 in a row
			JOptionPane.showMessageDialog(null, "The game has ended in a stalemate!");
			resetBoard();   
		}
	}
	
	/**
		turn method goes through the turn logic depending on which button you press
	*/
	public void turn(ActionEvent e, Boolean turn){
		if(inGame){ //if the game is in progress, allow turn logic to progress
            
			//initialize and scale puppy/kitten pictures to replaces Xs and Os
			ImageIcon puppyIcon = new ImageIcon("puppy.jpg");
            ImageIcon kittensIcon = new ImageIcon("kitten.jpg");
            Image puppyImage = puppyIcon.getImage();
            Image kittensImage = kittensIcon.getImage();
            Image scaledPuppies = puppyImage.getScaledInstance((int) (button1.getSize()).getWidth(), (int) (button1.getSize()).getHeight(), java.awt.Image.SCALE_SMOOTH);
            Image scaledKittens = kittensImage.getScaledInstance((int) (button1.getSize()).getWidth(), (int) (button1.getSize()).getHeight(), java.awt.Image.SCALE_SMOOTH);
            puppyIcon = new ImageIcon(scaledPuppies);
            kittensIcon = new ImageIcon(scaledKittens);
            
            
            if(e.getSource() == button1) //if the top left button was pressed
            {  
                if(!checked1){ //if it hasn't already been pressed
                    checked1 = true; //set boolean to say that it has now been pressed
                    if(turn) //if it's player 1s turn
					{
                        button1.setIcon(puppyIcon); //set the button to display the puppy image
                        button1Player1 = true; //say that it was player 1 that pressed the button
                        player1Turn = false; //say that it is no longer player 1s turn
                        statusLabel.setText(player2Name + "'s turn"); //update status label to say whos turn it is 
                    } 
					else //else if it's player 2s turn
					{
                        button1.setIcon(kittensIcon); //set the button to display the kitten image
                        button1Player2 = true; //sau that it was player 2 that pressed the button
                        player1Turn = true;  //say that it is no longer player 2s turn
                        statusLabel.setText(player1Name + "'s turn"); //update status label to say whos turn it is
                        
                    }   
					//after button logic, check if the game has been won/stalemated
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button2) //same logic as above but if top middle button was pressed
            {
                if(!checked2)
				{
                    checked2 = true;
                    if(turn)
					{
                        button2.setIcon(puppyIcon);
                        button2Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button2.setIcon(kittensIcon);
                        button2Player2 = true;
                        player1Turn = true; 
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button3) //same logic as above but if top right button was pressed
            {
                if(!checked3){
                    checked3 = true;
                    if(turn)
					{
                        button3.setIcon(puppyIcon);
                        button3Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button3.setIcon(kittensIcon);
                        button3Player2 = true;
                        player1Turn = true; 
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button4) //same logic as above but if middle left button was pressed
            {
                if(!checked4)
				{
                    checked4 = true;
                    if(turn)
					{
                        button4.setIcon(puppyIcon);
                        button4Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button4.setIcon(kittensIcon);
                        button4Player2 = true;
                        player1Turn = true; 
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button5) //same logic as above but if middle center button was pressed
            {
                if(!checked5)
				{
                    checked5 = true;
                    if(turn)
					{
                        button5.setIcon(puppyIcon);
                        button5Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button5.setIcon(kittensIcon);
                        button5Player2 = true;
                        player1Turn = true; 
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button6) //same logic as above but if middle right button was pressed
            {
                if(!checked6)
				{
                    checked6 = true;
                    if(turn)
					{
                        button6.setIcon(puppyIcon);
                        button6Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button6.setIcon(kittensIcon);
                        button6Player2 = true;
                        player1Turn = true;
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button7) //same logic as above but if bottom left button was pressed
            {
                if(!checked7)
				{
                    checked7 = true;
                    if(turn)
					{
                        button7.setIcon(puppyIcon);
                        button7Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button7.setIcon(kittensIcon);
                        button7Player2 = true;
                        player1Turn = true;
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button8) //same logic as above but if bottom middle button was pressed
            {
                if(!checked8)
				{
                    checked8 = true;
                    if(turn)
					{
                        button8.setIcon(puppyIcon);
                        button8Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button8.setIcon(kittensIcon);
                        button8Player2 = true;
                        player1Turn = true;
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
            else if(e.getSource() == button9) //same logic as above but if bottom right button was pressed
            {
                if(!checked9)
				{
                    checked9 = true;
                    if(turn)
					{
                        button9.setIcon(puppyIcon);
                        button9Player1 = true;
                        player1Turn = false;
                        statusLabel.setText(player2Name + "'s turn");
                    } 
					else 
					{
                        button9.setIcon(kittensIcon);
                        button9Player2 = true;
                        player1Turn = true; 
                        statusLabel.setText(player1Name + "'s turn");
                    }
                    checkIfGameOver();
                }
            }
        }
	}
    
	public static void main(String[] args) 
	{
        new TicTacToe(); //create the gui
    }
    
}
