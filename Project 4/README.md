This was my fourth CS 100 project.

Grade: 100%

In this project, given a CSV gradebook, perform the following operations:

double getMin(char csvfile[], char column[]); Given a CSVfile, return the minimum score of the specified column. The blank cells are excluded from the calculation.

double getMax(char csvfile[], char column[]); Given a CSVfile, return the maximum score of the specified column. The blank cells are excluded from the calculation.

double getAvg(char csvfile[], char column[]); Given a CSVfile, return the average score of the specified column. The blank cells are excluded from the calculation.

int getCount(char csvfile[], char column[], double threshold); Given a CSVfile, return the number of students with their specified score >= threshold.The blank cells are excluded from the calculation.

double getGrade(char csvfile[], char first[], char last[]); Given a CSV file, return the weighted average of the specified student. The weight for each column is specified in the corresponding column heading within the parentheses(points). A blank cell is viewed as 0 in the calculation.
