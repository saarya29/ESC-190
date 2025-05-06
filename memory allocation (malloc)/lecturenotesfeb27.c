char *find_max_average(char *files[], int num_files)
{
    int i; 
    char line[100];
    char cur_students[100];
    double cur_max_average = 0;
    char *max_student = malloc(11*sizeof(char));
    for (i = 0; i< num_files; i++)
    {
        FILE *fp = fopen(files[i], "r");
        while (fgets(line, 100, fp)! = NULL)
        {
            strncpy(cur_students, line, 10);

            double cur_average = find_average(files, num_files, cur_students);
            if (cur_average > cur_max_average)
            {
                cur_max_average = cur_average;
                strcpy(max_studen, cur_student);
            }
        }
    }
    return max_student;
}