# Huffman 

A Huffman tree is a type of binary tree used in data compression to efficiently encode information. It is built based on the frequency of each character in a given text: characters that appear more often are assigned shorter binary codes, while less frequent characters receive longer ones.
The tree is constructed by repeatedly combining the two least frequent nodes into a new parent node, until only one tree remains. Each leaf of the tree represents a character, and the path from the root to that leaf defines its binary code (typically using 0 for left and 1 for right).

In this exercise, we are going to generate the Huffman tree depending on a input text. Then, we are going to use that tree to code and decode the input text. 

## Threshold 0 

The first step of the tree generation is to determine the frequency of each character that composes the input message. For instance, in the word "mississippi", we have :
- freq 'm' = 1 / 11
- freq 'i' = 4 / 11
- freq 's' = 4 / 11
- freq 'p' = 2 / 11

## Threshold 1

Using the frequency of each character, we can create the binary tree that we are going to use.

1. For each character, create a `Node` containing the character and its frequency.
2. Select the two nodes with the lowest frequency. Create a parent `Node` that will have the node with the lowest frequency as its left child and the other node as its right child. The frequency of the parent `Node` is the sum of the frequency of its children. (The `Token` is left to '\0').
3. Remove the two children nodes from the list of nodes you have created on step 1 and insert the parent node.
4. Repeat the process until you have only one Node which will become the root node.

In our example, we will have (for clarity and identification reasons, we are using the sum instead of the frequency to identify the node. but your implementation should use frequency): 

                            (11)
                          /      \
                       s(4)      (7)      
                                /   \
                              (3)   i(4)
                             /   \
                           m(1)  p(2)

So :
m = 100
p = 101
i = 11
s = 0

## Threshold 2

Now we have this tree, we can use it to code and decode any message.

Let's start with the simplest one : encode.
```cpp
std::string Encode(const std::string& inputMessage) const;
```

To do so, for each character you encounter in the given message, replace each character by its Huffman representation

> For now, we are using string to visualize the result, so it might seem useless. Keep in mind that this algorithm is using bits to encode and not bytes (char), so you have to divide the size of the encoded message by 8.

## Threshold 3

Implement the function 
```cpp
std::string Decode(const std::string& encodedMessage) const;
```

The string that this function received is encoded. That means that it is only composed of 0 and 1.
For each character, follow the Huffman tree from the root until you reach a leaf. If the character is a 0, follow the left child. Otherwise, follow the right child. If there is no child to follow, then use the `Token` variable of the current node.

For instance, if my encoded message is: `101011` the decode function should return `psi`.
- From root node, found a 1 => right
- From 7 freq node, second char is 0 => left
- From 3 freq node, third char is 1 => right
    - This is a leaf, so the first letter is p
- From root node, fourth char is 0 => left
    - This is a leaf, so the second letter is s
- From root node, fifth char is 1 => right
- From 7 freq node, second char is 1 => right
    - This is a leaf, so the third letter is i

**The `main` function is the only one that must not contain any code because it will be replaced. All code in that function will be lost. However, you can use it as a sandbox, you are free to use the way you want while developing.**

# Notes
- Containers like std::priority_queue might be useful
- Be careful about memory leaks