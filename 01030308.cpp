#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>


using namespace std;
class Quiz
{
protected:
	map<string, vector<string>> mquestion;
	vector<string> questions;
public:
	void intQuestions()
	{
		string one = " акой тип данных используетс€ дл€ хранени€ целых чисел в C++?";
		string two = " акой тип данных следует использовать дл€ представлени€ результатов целочисленных операций?";
		string three = " акой тип переменной использовать, если нужно хранить только целые значени€ без дес€тичных долей?";
		string four = " аков тип данных дл€ представлени€ индексов в массиве с целыми числами?";
		string five = " акое ключевое слово указывает на использование целочисленного числового типа?";

		questions.reserve(5);
		questions.push_back(one);
		questions.push_back(two);
		questions.push_back(three);
		questions.push_back(four);
		questions.push_back(five);

		mquestion["int"] = questions;
	}

	void countdown(int seconds, bool& timerExpired)
	{
		for (int i = seconds; i > 0; --i) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			if (!timerExpired) {
				std::cout << "\rќсталось времени: " << i << " секунд";
				std::cout.flush();
			}
		}
		timerExpired = true;
	}

	string getAnsw()
	{
		string a;
		getline(cin, a);
		return a;
	}

	void start()
	{
		intQuestions();

		map<string, vector<string>>::iterator it;
		int res = 0;
		int win = 6;
		int seconds = 60;
		string answ;

		cout << "¬ам будт задано 5 вопросов" << endl;
		this_thread::sleep_for(chrono::seconds(2));
		cout << "ѕеред ответом вам будет дано " << seconds << " секунд на раздумываени€" << std::endl;
		this_thread::sleep_for(chrono::seconds(2));
		cout << endl;
		cout << endl;


		for (int i = 0; i < 5; ++i)
		{
			it = mquestion.begin();
			chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
			chrono::steady_clock::time_point end_time = start_time + chrono::seconds(seconds);

			cout << it->second[i] << endl;
			bool timerExpired = false;

			for (int i = seconds; i > 0; --i)
			{
				this_thread::sleep_for(chrono::seconds(1));
				if (!timerExpired) {
					cout << "\rќсталось времени: " << i << " секунд";
					cout.flush();
				}
			}
			cout << "\r ¬ведите ответ ниже:             " << endl;

			getline(cin, answ);
			if (answ == it->first)
			{
				res += --win;
			}
			else if (answ != it->first) --win;
			cout << endl;
			cout << endl;

		}

		cout << endl;
		cout << "ѕравильный ответ: " << it->first << endl;
		cout << "¬ы заработали " << res << " балов!" << endl;

	}
};

int main()
{
	system("chcp 1251 > nul");

	Quiz g;
	g.start();


	return 0;
}