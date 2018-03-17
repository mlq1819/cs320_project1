# cs301-project1
Submission Due on Mycourses: Saturday, March 17th at 10pm
Project demos: during lab sessions and office hours on Tuesday, March 20th
The goal of this project is to measure the effectiveness of various branch direction prediction (“taken” or “non-taken”) schemes on several traces of conditional branch instructions. Each trace contains a large number of branch instructions, and for each branch, the program counter (expressed as a word address) and the actual outcome of the branch are recorded in one line of the trace file. Several trace files are provided for evaluating your predictor designs.
Your goal is to write a program in C or C++ that would use these traces to measure the accuracy of various dynamic branch predictors that we studied in class. The branch outcomes from the trace file should be used to train your predictors. You will need to present results for each trace separately, details of what exactly needs to be submitted are provided below. 
The following predictors have to be implemented:
[5%] Always Taken. 
[5%] Always Non-Taken.
[20%] Bimodal Predictor with a single bit of history stored in each predictor entry. Determine the prediction accuracy of this predictor for the table size of 16, 32, 128, 256, 512, 1024 and 2048 entries. Assume that the initial state of all prediction counters is “Taken” (T)
[20%] Bimodal Predictor with 2-bit saturating counters stored in each predictor entry. Repeat the same experiments as in part (3) above. Assume that the initial state of all prediction counters is “Strongly Taken” (TT)
[25%] Gshare predictor, where the PC is XOR-ed with the global history bits to generate the index into the predictor table. Fix the table size at 2048 entries and determine the prediction accuracy as a function of the number of bits in the global history register. Vary the history length from 3 bits to 11 bits in 1-bit increments. Assume that the initial state of all prediction counters is “Strongly Taken” (TT). The global history register should be initialized to contain all zeroes (where 0=NT and 1=T). The global history register should be maintained such that the least significant bit of the register represents the result of the most recent branch, and the most significant bit of the register represents the result of the least recent branch in the history.
[25%] Tournament Predictor. The tournament predictor selects between gshare and bimodal predictor for every branch. Configure gshare with 2048-entry table and 11 bits of global history, and configure bimodal predictor with 2048-entry table. Furthermore, configure the selector table with 2048 entries and use the same index as you use for bimodal predictor to index into the selector table (that is, the PC). For each entry in the selector, the two-bit counter encodes the following states: 00 – prefer Gshare, 01 – weakly prefer Gshare, 10 – weakly prefer Bimodal, 11 – prefer bimodal. If the two predictors provide the same prediction, then the corresponding selector counter remains the same. If one of the predictors is correct and the other one is wrong, then the selector’s counter is decremented or incremented to move towards the predictor that was correct. Initialize all the component predictors to “Strongly Taken” and initialize the selector’s counters to “Prefer Gshare”.

Materials on Mycourses:
There is a tar/gzipped archive of materials on Mycourses that contains the following:
A sample output file called sample_output.txt complete with comments
A directory called examples, containing short snippets of code that show how to	read the input
A directory called traces, containing the following 6 trace files:
	long_trace1.txt (23532921 branch instructions)
long_trace2.txt (27946011 branch instructions)
long_trace3.txt (14796021 branch instructions)
short_trace1.txt (3771697 branch instructions)
short_trace2.txt (2866495 branch instructions)
	short_trace3.txt (2229289 branch instructions)
A directory called correct_outputs, containing the correct outputs for the given 	traces.  These can and should be used to check that your program works 	correctly and outputs the results in the required format.
	
To access these materials, download a copy from Mycourses, cd into the directory where you placed the tar/gzipped archive and issue the following command:
tar -xzvf project1.tar.gz
This will create a new directory (named project1) containing the files mentioned above.
Submission requirements:
NOTE: Please carefully read and follow all directions while preparing your submissions.  Submissions will be graded using a script and failure to follow these directions will likely end up crashing the script causing the TAs to have to grade your submission by hand.  If this happens points will be deducted from your grade.  Examples of things to watch out for: the directory inside your tar archive isn't named with your BU-ID, incorrectly named executable after 'make', using standard input and output for I/O, and not using command-line arguments for the names of the input and output files.
You need to submit your source code, so that we can compile it and test for correctness. For checking your code, we will be using the same traces that you used for generating your results, plus some more traces that you will not have access to. 
The code that you submit should compile into a single executable called predictors with a simple `make` command. This executable should run all of the predictors on the given trace, which will be specified via command line options as follows:
./predictors input_trace.txt output.txt
Where: -input_trace.txt – file containing branch trace
	  -output.txt – file to place output statistics
The output file should have the following format: (an example text file is on Mycourses too with comments, which should not be output by your program)
#,@;
#,@;
#,@; #,@; #,@; #,@; #,@; #,@; #,@;
#,@; #,@; #,@; #,@; #,@; #,@; #,@;
#,@; #,@; #,@; #,@; #,@; #,@; #,@; #,@; #,@;
#,@;
Where each 
# corresponds to the number of correct predictions made by each of the predictors 
@ corresponds to the number of branches.
First line: Provides the number of correct predictions for the always taken predictor
Second line:  Provides the number of correct predictions for the always taken predictor
Third line: Gives the correct predictions for all seven variations of the bimodal predictor with a single bit of history (Table of size 16, 32 …. Etc). Check the first page for required variations.
Fourth line: Repeats the third line for the two bit saturating counter based bimodal predictor
Fifth Line: shows the number of correct predictions for the nine variations of Gshare predictor. 
The last line: The tournament predictor. 
The number of correct predictions and branches should be separated by a comma. 
Every configuration of predictor should be separated by a semicolon(;) and a space. 
Submissions will be checked using a script that will compare your output file to the correct output file using the UNIX `diff` tool, so if your output does not EXACTLY match the correct output the grading program will mark it as wrong. The TA will have to check such submissions by hand which will result in at least a few points being deducted. 

