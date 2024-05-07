/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author HP
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class assi {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read user input
        
        // 1 Ask the user for a string input
        System.out.print("Enter a string: ");
        String myString = scanner.nextLine(); // Read the input from the user
        
        
                
        // 2 Convert the string to a character list
        List<Character> mylistchar = new ArrayList<>();
        for (char c : myString.toCharArray()) {
            mylistchar.add(c);
        }
        // Display the character list
        System.out.print("Character List: ");
        for (char c : mylistchar) {
            System.out.print(c + " ");
        }
        System.out.println();

        
        
        // 3 Create an integer list from the character list
        List<Integer> mylistint = new ArrayList<>();
        for (char c : mylistchar) {
            mylistint.add((int) c); 
        }
        // Display the integer list
        System.out.print("Integer List: ");
        for (int num : mylistint) {
            System.out.print(num + " ");
        }
        System.out.println();

        
        
        // 4 XOR each element with 127 and create a new integer list
        List<Integer> mylistintnew = new ArrayList<>();
        for (int num : mylistint) {
            mylistintnew.add(num ^ 127); // XOR with 127
        }
        // Display the new integer list
        System.out.print("New Integer List: ");
        for (int num : mylistintnew) {
            System.out.print(num + " ");
        }
        System.out.println();

        
        
        // 5 Convert the new integer list to a character list
        List<Character> mylistcharnew = new ArrayList<>();
        for (int num : mylistintnew) {
            mylistcharnew.add((char) num);
        }
        // Display the new character list
        System.out.print("New Character List: ");
        for (char c : mylistcharnew) {
            System.out.print(c + " ");
        }
        System.out.println();

        // 6 Convert the new character list to a string
        StringBuilder resultString = new StringBuilder();
        for (char c : mylistcharnew) {
            resultString.append(c); // Convert to String
        }

        System.out.println("Result String: " + resultString.toString()); // Print the final result
        
        scanner.close(); // Don't forget to close the scanner when done
    }
}
