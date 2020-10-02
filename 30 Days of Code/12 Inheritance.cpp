// problem source: https://www.hackerrank.com/challenges/30-inheritance/problem
// discussion reference: https://www.hackerrank.com/challenges/30-inheritance/forum/comments/133864
#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}

};

class Student :  public Person{
    private:
        vector<int> testScores;
    public:
        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        //Q: Below code is not working. How can working by below code?
        //Student(string firstName, string lastName, int identification, std::vector<int> scores) {
        //  Person(firstName, lastName, identification);
        //  testScores = scores;
        //}
        Student(string firstName, string lastName, int identification, std::vector<int> score) : Person(firstName, lastName, identification), testScores(score) { }
        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate() {
          int sum = 0;
          int average;
          for (int i = 0; i < testScores.size(); i++)
            sum += testScores[i];
          average = sum / testScores.size();
          if (average >= 90 && average <= 100)
            return 'O';
          else if (average >= 80 && average < 90)
            return 'E';
          else if (average >= 70 && average < 80)
            return 'A';
          else if (average >= 55 && average < 70)
            return 'P';
          else if (average >= 40 && average < 55)
            return 'D';
          else // average < 40
            return 'T';
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
