# CS-300-Analysis-Design
# What was the problem you were solving in the projects for this course?
In these projects I was tasked with planning and creating a software for academic advisors in the computer science department at a university. This software needed to read and extract data from a file to store it in the appropriate data structure. The software had to display a alphanumeric sorted list of all courses, allow users to search for a specific course, and show its prerequisites if there were any. 

# How did you approach the problem? Consider why data structures are important to understand.
I used a hash table to store course data for fast lookup and a vector to sort and display courses alphabetically. Understanding data structures helped me choose the right ones for speed based on the program’s needs.

# How did you overcome any roadblocks you encountered while going through the activities or project?
The hardest part was parsing the file and handling each course prerequisite. Some of the lines had missing or extra data which caused errors. I overcame this by writing a custom parser that split lines by commas and checked each line had at least a course ID and name. I also added checks to make sure all prerequisites existed in the course list. With this I was able to properly store the data and display it in the correct order.

# How has your work on this project expanded your approach to designing software and developing programs?
This project taught me to plan ahead and break down each problem. Although you may have the right outline to begin with there will still need to be some changes made to turn your outline into a functioning product.

# How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
I focused on writing clean code and ensured that every line I did was noted. This made my code easier to read, debug, and modify. If there were to be any new features added in the future this layout will make it easier to expand and adapt.
