# Pythagorean-Tree

# PS3: Pythagorean Tree

## Contact
Name: Truong-Thinh Huynh
Section: 201
Time to Complete: 10 Hours


## Description
Explain what the project does.

The main purpose of the project is to draw a Pythagoras tree using recursion. The program is expected to take two command-line arguments as default. The first command-line argument is the length of the square and the other is the depth of the recursion. Then we have to draw the window that the tree will be draw in by using the dimention 6 * length x 4 * length. After setting the window, I called pTree that is doing the recursion by going to all of the left child until it depth is less than 1, which it will switch to the right child. But during each recursion, every properties is set and send into a vector containing rectangleShape. Then all of these shape will be draw in the draw() function.

Additionally, this project also takes a third argument of angle that will replace the default 45 degree. This will allow the tree to be drawn based on the angle of degree. And the tree now will have color that is different based on the level depth. And lastly, the color will be contiously cycle for each shape so that it will look like a gradiant of color.


### Features
Describe what your major decisions were and why you did things that way.

The most major decision was definitely how I would set the position, origin, and rotate of each shape. So what I decided is the left child will follow their parent, while the right child will follow their left child. So the base square is set at origin on top left and the left child as bottom left. This will allow my left child to rotate left while having the origin be an anchor to the parent. But the right will also set the origin as bottom left but their anchor will be on the bottom right of the left child. This will allow the right child to rotate right. The reason for this is to fill in the gap so that all three shape will form a triangle or right triangle when calling the default program.

The second major decision was how I was to going to draw the shapes. So I decided that I will set a member as a vector of rectangleShape, and I will continue to push these shape into the vector and then draw it in my draw() later.

The third major decision was how to implement a gradiant for my extra credit. I have decided that I should store how many colors based on the depth in a vector. Then every time the main window loop is run, the vector will move by 1 while the color at position 0 will be at the end. This will makes it seemes like the tree is shifting color in a gradiant, rather than having one color for each depth that doesn't change.

How To Use:

Default: ./PTree length depth

Extra Credit: ./PTree length depth angle

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

Everything works as I intended and it is completed all of the requirements when I tested it. But the only thing that I'm not sure if it is correct is the sizes window to fit image, as even through the tree fit in the window, there is still a little bit of space between the tree and the window. And the pdf said it should fit snugly, so I'm not sure if it is within the requirement as I did follow the 6 * L x 4 * L for the dimension of the window. On top of that, if you run the program with an angle instead of the default 45 degree, if the angle is too large, the whole entire will spill out of the window. But this is only during the extra credit test, and the normal tree is fit within the window.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

The first extra credit is when you run the program without a third argument that takes an int angle, it will run the default 45 degree. But if you add an angle, then the program will run the extra credit program. By adding an angle in the line-command arguments, you are now able to build a tree with the inputted angle rather than the default 45 degree.

The second extra credit is for each depth, there is a different color for the rectangle shape.

And the other reasonable extension is on top of having a different color for each depth, there is also a gradiant color that continously change color each time and will repeat when it loop through all of the color option. This will create a gradiant from the base to the top of the tree.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

None
