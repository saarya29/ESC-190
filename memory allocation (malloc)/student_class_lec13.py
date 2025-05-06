class Student: 
    #void create_student(student **s, char *major, double gpa)
    #*s = malloc(...)
    #(*s)->major = major;
    #(*s)-> gpa = gpa; trying to show the correlation between python and C. 
    #structs are quite similar to classes in python. 

    def __init__(self, major, gpa):
        self.major = major
        self.gpa = gpa

    def print_student(self):
        print(f"Major: {self.major}, GPA: {self.gpa}")
        if self.gpa > 3.6:
            print("DEAN'S LIST")

    s = Student("Robo", 3.8)
    s2 = Student("MI", 3.9)

    s.print_student() #s.print_student(s)

    s.major
    s2.gpa