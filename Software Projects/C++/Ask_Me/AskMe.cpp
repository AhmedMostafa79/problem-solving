/***************************************************************
 *                      Ask Me Project                         *
 *                                                             *
 * A simple Q&A platform using C++                             *
 *                                                             *
 *															   *
 * Modules:                                                    *
 *  - File Handling                                            *
 *  - User Management                                          *
 *  - Question Management                                      *
 *															   *
 *															   *
 ***************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define users_file_path "E:\\Github\\Main\\Projects\\C++\\Ask_Me\\Users_Manager.txt"
#define questions_file_path "E:\\Github\\Main\\Projects\\C++\\Ask_Me\\Questions_Manager.txt"

vector<string> ReadFileLines(const string& path) {
	vector<string> lines;
	ifstream file(path);
	if (!file) {
		cerr << "Error invalid file path!: " << path << '\n';
		return lines;
	}
	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}
	file.close();
	return lines;
}

/***************************************************************
 *                      Helper Functions                       *
 ***************************************************************/

void WriteFileLines(const string& path, const vector<string>& lines, bool append = true) {
	auto open_mode = append ? ios::app : ios::trunc;
	ofstream file(path, open_mode);
	if (!file) {
		cerr << "\n\nError invalid file path!: " << path << "\n\n";
		return;
	}
	for (const auto& line : lines) {
		file << line << '\n';
	}
	file.close();
}

vector<string> SplitString(const string& line, const char& delimeter = ',') {
	string s = line;
	vector<string> data;
	int i = 0;
	while (~s.find(delimeter, i)) {
		string sub;
		sub = s.substr(i, s.find(delimeter, i) - i);
		data.push_back(sub);
		i = s.find(delimeter, i + 1) + 1;
	}
	data.push_back(s.substr(i));
	return data;
}

int ReadInt(const int& low, const int& high) {
	while (true) {
		int num;
		cout << "\nEnter number in range " << low << " - " << high << " : ";
		cin >> num;
		if (low <= num && num <= high) {
			return num;
		}
		cout << "Invalid number! Please try again.\n";
	}
}

int ShowReadMenu(const vector<string>& choices) {
	cout << "\n\n***** Menu *****\n\n\n";
	for (int choice = 0; choice < choices.size(); choice++) {
		cout << "Choice " << choice + 1 << ": " << choices[choice] << '\n';
	}
	int choice = ReadInt(1, choices.size());
	return choice;
}



int ToInt(const string& str) {
	istringstream iss(str);
	int num;
	iss >> num;

	return num;
}


/***************************************************************
 *                      User Class                             *
 ***************************************************************/
class User {
	int user_id;
	string name;
	string username;
	string password;
	string email;
	int allow_anonymous_question;
	vector<int>questions_id_from_me;
	map<int, vector<int>>questions_id_to_me;
public:
	User() :user_id(-1), allow_anonymous_question(-1) {};
	User(const string& line) {
		vector<string>data = SplitString(line);
		assert(data.size() == 6);
		SetUserId(ToInt(data[0]));
		SetUserName(data[1]);
		SetPassword(data[2]);
		SetName(data[3]);
		SetEmail(data[4]);
		SetAllowAnonymousQuestion(ToInt(data[5]));
	}
	string ToString()const {
		ostringstream user_info;
		user_info << to_string(user_id) << "," << username << "," << password << "," << name << "," << email << "," << allow_anonymous_question;
		return user_info.str();
	}
	void Print() const {
		cout << "User Id: " << GetUserId() << '\n';
		cout << "User Name: " << GetUserName() << '\n';
		cout << "Name: " << GetName() << '\n';
		cout << "Password: " << GetPassword() << '\n';
		cout << "Email: " << GetEmail() << '\n';
	}
	void ReadUser(const string& user_name, const int& user_id) {
		SetUserName(user_name);
		SetUserId(user_id);
		string s;
		cout << "Enter your Name: ";
		cin >> s;
		SetName(s);
		cout << "Enter Password: ";
		cin >> s;
		SetPassword(s);
		cout << "Enter your Email: ";
		cin >> s;
		SetEmail(s);
		int n;
		cout << "Do you allow anonymous Questions? 1(YES) , 0(NO): ";
		cin >> n;
		SetAllowAnonymousQuestion(n);
	}

	void ResetQuestionsToMe(const vector<pair<int, int>>& to_questions) {
		questions_id_to_me.clear();

		for (const auto& question : to_questions) {
			questions_id_to_me[question.first].push_back(question.second);
		}
	}

	void ResetQuestionsFromMe(const vector<int>& from_questions) {
		questions_id_from_me.clear();
		for (const auto& question_id : from_questions) {
			questions_id_from_me.push_back(question_id);
		}
	}


	void SetUserId(const int& user_id) {
		this->user_id = user_id;
	}

	const int& GetUserId()const {
		return user_id;
	}

	void SetName(const string& name) {
		this->name = name;
	}
	const string& GetName()const {
		return name;
	}
	void SetUserName(const string& username) {
		this->username = username;
	}
	const string& GetUserName() const {
		return username;
	}

	void SetPassword(const string& passwd) {
		this->password = passwd;
	}
	const string& GetPassword()const {
		return password;
	}
	void SetEmail(const string& email) {
		this->email = email;
	}
	const string& GetEmail()const {
		return email;
	}
	void SetAllowAnonymousQuestion(bool allow_an_q) {
		this->allow_anonymous_question = allow_an_q;
	}
	const bool& IsAllowAnonymousQuestion()const {
		return allow_anonymous_question;
	}

	//each question from me with its id and its thread id

	const vector<int>& GetQuestionsIdFromMe()const {
		return questions_id_from_me;
	}
	const map<int, vector<int>>& GetQuestionsIdToMe() const {
		return questions_id_to_me;
	}
};

/***************************************************************
 *                      Question Class                         *
 ***************************************************************/
class Question {
	int question_id;
	int parent_question_id;
	int from_user_id;
	int  to_user_id;
	int is_anonymous_quesion;
	string question_text;
	string answer_text;

public:
	Question() :question_id(-1), parent_question_id(-1), from_user_id(-1),
		to_user_id(-1), is_anonymous_quesion(-1) {
	};
	Question(const string& line) {
		vector<string>data = SplitString(line);
		assert(data.size() == 7);
		SetQuestionId(ToInt(data[0]));
		SetParentQuestionId(ToInt(data[1]));
		SetFromUserId(ToInt(data[2]));
		SetToUserId(ToInt(data[3]));
		SetIsAnonymousQuestion(ToInt(data[4]));
		SetQuestionText(data[5]);
		SetAnswerText(data[6]);
	}
	string ToString() const {
		ostringstream ss;
		ss << GetQuestionId() << "," << GetParentQuestionId() << "," << GetFromUserId() << "," <<
			GetToUserId() << "," << GetIsAnonymousQuestion() << "," << GetQuestionText() << "," <<
			GetAnswerText();
		return ss.str();
	}

	void Print() const {
		cout << "Question Id: " << GetQuestionId() << '\n';
		cout << "Parent Question Id: " << GetParentQuestionId() << '\n';
		cout << "From User: " << GetFromUserId() << '\n';
		cout << "To User: " << GetToUserId() << '\n';
		cout << "IsAnonymous:  " << GetIsAnonymousQuestion() << '\n';
		cout << "Question Text: " << GetQuestionText() << '\n';
		cout << "Answer Text: " << GetAnswerText() << '\n';
	}

	void PrintToQuestion() const {
		//if(GetParentQuestionId()==-1)
			//cout<<""
		cout << "Question Id: " << GetQuestionId();
		cout << "\t\tFrom user: ";
		if (!GetIsAnonymousQuestion())
			cout << GetFromUserId();
		else
			cout << "Unknown";;
		cout << "\n\tQuestion: " << GetQuestionText() << '\n';;
		if (GetAnswerText().empty())
			cout << "\tNot answered Yet!\n";
		else
			cout << "\tAnswer: " << GetAnswerText() << '\n';
		cout << "\n";
	}

	void PrintFromQuestion() const {
		//if(GetParentQuestionId()==-1)
			//cout<<""
		cout << "Question Id: " << GetQuestionId();

		cout << "\t\tTo user: " << GetToUserId();

		cout << "\nQuestion: " << GetQuestionText() << '\n';;
		if (GetAnswerText().empty())
			cout << "\tNot answered Yet!\n";
		else
			cout << "\tAnswer: " << GetAnswerText() << '\n';
		cout << "\n";
	}
	void PrintFeedQuestion()const {
		cout << "Thread Question Id: " << ' ';

		if (GetParentQuestionId() == -1)
			cout << GetQuestionId();
		else cout << GetParentQuestionId();

		cout << "\nQuestion Id: " << GetQuestionId() << '\n';
		cout << "From user: ";

		if (!GetIsAnonymousQuestion())
			cout << GetFromUserId();
		else cout << "Unknown";
		cout << "\t\tTo User: " << GetToUserId() << '\n';

		cout << "\tQuestion: " << GetQuestionText() << '\n';
		cout << "\tAnswer: " << GetAnswerText() << '\n';
	}
	void SetQuestionId(const int& question_id) {
		this->question_id = question_id;
	}

	const int& GetQuestionId() const {
		return question_id;
	}

	void SetParentQuestionId(const int& parent_question_id) {
		this->parent_question_id = parent_question_id;
	}

	const int& GetParentQuestionId() const {
		return parent_question_id;
	}


	void SetFromUserId(const int& from_id) {
		this->from_user_id = from_id;
	}

	const int& GetFromUserId()const {
		return from_user_id;
	}

	void SetToUserId(const int& to_id) {
		this->to_user_id = to_id;
	}

	const int& GetToUserId()const {
		return to_user_id;
	}

	void SetIsAnonymousQuestion(const int& is_an_question) {
		this->is_anonymous_quesion = is_an_question;
	}

	const int& GetIsAnonymousQuestion()const {
		return is_anonymous_quesion;
	}

	void SetQuestionText(const string& text) {
		this->question_text = text;
	}

	const string& GetQuestionText()const {
		return question_text;
	}

	void SetAnswerText(const string& answer) {
		this->answer_text = answer;
	}

	const string& GetAnswerText()const {
		return answer_text;
	}

};

/***************************************************************
 *                 Questions Manager Class                     *
 ***************************************************************/
class QuestionsManager {
	//stores each thread's parent_question id
	map<int, vector<int>>threads_headquestions_ids;
	//maps each question_id with its question object
	map<int, Question>questions;
	int last_id;
public:
	QuestionsManager() :last_id(0) {}

	void LoadDataBase(const string& file_path = questions_file_path) {
		last_id = 0;
		threads_headquestions_ids.clear();
		questions.clear();
		vector<string>lines = ReadFileLines(file_path);
		for (const auto& line : lines) {
			Question question(line);

			if (question.GetParentQuestionId() == -1)
				threads_headquestions_ids[question.GetQuestionId()].push_back(question.GetQuestionId());
			else
				threads_headquestions_ids[question.GetParentQuestionId()].push_back(question.GetQuestionId());

			questions[question.GetQuestionId()] = question;
			last_id = max(last_id, question.GetQuestionId());
		}
	}

	vector<int>GetUserToQuestions(const User& user) const {
		vector<int>to_questions;
		for (const auto& thr : threads_headquestions_ids) {
			for (const auto& question_id : thr.second) {
				const Question& question = questions.find(question_id)->second;
				if (question.GetFromUserId() == user.GetUserId()) {
					if (question.GetParentQuestionId() == -1)
						to_questions.push_back(question.GetQuestionId());

				}
			}
		}
		return to_questions;
	}

	vector<pair<int, int>>GetUserFromQuestions(const User& user) const {
		vector<pair<int, int>>from_questions;

		for (const auto& thr : threads_headquestions_ids) {
			for (const auto& question_id : thr.second) {

				const Question& question = questions.find(question_id)->second;

				if (question.GetToUserId() == user.GetUserId()) {
					if (question.GetParentQuestionId() == -1)
						from_questions.push_back({ question.GetQuestionId(),question.GetQuestionId() });
					else
						from_questions.push_back({ question.GetParentQuestionId(),question.GetQuestionId() });
				}
			}
		}
		return from_questions;
	}

	void PrintUserFromQuestions(const User& user) const {
		if (user.GetQuestionsIdFromMe().empty()) {
			cout << "No Questions!!\n";
			return;
		}

		for (const auto& thread_id : user.GetQuestionsIdFromMe()) {
			cout << "Thread Number: " << thread_id << '\n';
			const auto& thread_questions = threads_headquestions_ids.find(thread_id);
			if (thread_questions != threads_headquestions_ids.end()) {
				for (const auto& question_id : thread_questions->second) {
					const Question& question = questions.at(question_id);
					question.PrintFromQuestion();
				}
			}
		}
		cout << "\n";
	}

	void PrintUserToQuestions(const User& user) const {
		if (user.GetQuestionsIdToMe().empty()) {
			cout << "No Questions!!\n";
			return;
		}

		for (const auto& thread : user.GetQuestionsIdToMe()) {
			cout << "Thread Number: " << thread.first << '\n';
			for (const auto& question_id : thread.second) {
				const Question& question = questions.find(question_id)->second;
				question.PrintToQuestion();
			}
		}
		cout << "\n";
	}

	//if user wants to ask a question, then asks for its id
	int ReadQuestionId(const User& user)const {
		int question_id;
		cout << "Enter a question id or -1 to cancel: ";
		cin >> question_id;
		if (question_id == -1)
			return -1;
		if (!questions.count(question_id)) {
			cout << "\nError: No such question with such Id!!\n\n\n";
			return ReadQuestionId(user);
		}
		const Question& question = questions.find(question_id)->second;

		if (question.GetToUserId() != user.GetUserId()) {
			cout << "\nError: Invalid Question Id!!\n\n\n";
			return ReadQuestionId(user);
		}

		return question_id;
	}

	int ReadQuestionIdThread(const User& user) {
		int question_id;
		cout << "For a thread question: Enter Question id or -1 for new question: ";
		cin >> question_id;
		if (question_id == -1)
			return -1;

		if (!threads_headquestions_ids.count(question_id)) {
			cout << "\nError: No such thread question\n";
			return ReadQuestionIdThread(user);
		}
		return question_id;
	}

	void AnswerQuestion(const User& user) {
		int question_id = ReadQuestionId(user);
		if (question_id == -1)
			return;

		Question& question = questions.find(question_id)->second;
		if (!question.GetAnswerText().empty())
			cout << "\nQuestion already answered.. answer will be updated\n";

		cout << "Enter Answer: ";

		string ans;
		getline(cin, ans);//to ignore last cin
		getline(cin, ans);

		question.SetAnswerText(ans);
	}

	void DeleteQuestion(const User& user) {
		int question_id = ReadQuestionId(user);

		if (question_id == -1)
			return;

		int par_quest_id = questions[question_id].GetParentQuestionId();

		vector<int>question_thread;
		//if it is a thread's head question
	   // remove whole thread and the parent question from system
		if (threads_headquestions_ids.count(question_id)) {
			question_thread = threads_headquestions_ids[question_id];
			threads_headquestions_ids.erase(question_id);
		}
		//remove only the question from thread and from whole system
		else {
			question_thread.push_back(question_id);
			for (auto& pair : threads_headquestions_ids) {
				vector<int>& vec = pair.second;
				for (int pos = 0; pos < vec.size(); pos++) {
					if (question_id == vec[pos]) {
						vec.erase(vec.begin() + pos);
						break;
					}
				}
			}
		}
		for (const auto& id : question_thread) {
			questions.erase(id);
		}
	}

	void AskQuestion(const User& user, const pair<int, int>& to_user) {
		Question question;
		if (!to_user.second) {
			cout << "Warning!! user doesn't allow anonymous questions\n";
			question.SetIsAnonymousQuestion(0);
		}
		else {
			cout << "Is anonymous question? 0(No) , 1(Yes): ";
			int state;
			cin >> state;
			question.SetIsAnonymousQuestion(state);
		}
		int par_quest_id = ReadQuestionIdThread(user);

		string text;
		cout << "Enter question you want to ask: ";
		getline(cin, text);
		getline(cin, text);
		question.SetQuestionText(text);

		question.SetQuestionId(++last_id);

		question.SetFromUserId(user.GetUserId());
		question.SetToUserId(to_user.first);
		question.SetParentQuestionId(par_quest_id);

		questions[question.GetQuestionId()] = question;
		if (par_quest_id == -1) {//means its a thread head 
			threads_headquestions_ids[question.GetQuestionId()].push_back(question.GetQuestionId());
		}
		else {
			threads_headquestions_ids[question.GetParentQuestionId()].push_back(question.GetQuestionId());
		}

	}
	//prints all answered questions
	void ListFeed()const {
		cout << "Answered questions are:\n";
		for (const auto& pair : questions) {
			const Question& question = pair.second;
			//if (pair.second.GetAnswerText().empty())
					//continue;
			question.PrintFeedQuestion();
			cout << "\n";
			//cout << "Question: "<<question.second.GetQuestionText() << "\n";
			//cout <<"Answer: "<< question.second.GetAnswerText() << '\n';
		}
		cout << '\n';
	}

	void UpdateDatabase(const string& file_path = questions_file_path) const {
		vector<string>questions_str;
		for (const auto& question : questions) {
			questions_str.push_back(question.second.ToString());
		}
		//overwrites the questions_manager file with current questions int the system
		WriteFileLines(file_path, questions_str, false);
	}

};

/***************************************************************
 *                 Users Manager Class                         *
 ***************************************************************/
class UsersManager {
	map<string, User>users;
	User current_user;
	int last_id;
public:
	UsersManager() :last_id(-1) {}
	void LoadDatabase(const string& file_path = users_file_path) {
		users.clear();
		last_id = 0;
		vector<string>users_data = ReadFileLines(file_path);
		for (const auto& user_data : users_data) {
			User user(user_data);
			users[user.GetUserName()] = user;
			last_id = max(last_id, user.GetUserId());
		}
	}
	void AccessSystem() {
		LoadDatabase();
		int choice = ShowReadMenu({ "Login","Sign Up" });
		if (choice == 1) {
			if (DoLogin() == 0)
				AccessSystem();
		}
		else
			DoSignUp();

	}

	bool DoLogin() {
		LoadDatabase();//if user logged in from parallel run
		while (true) {
			string username, password;
			cout << "Enter Username or 0 to cancel: ";
			cin >> username;
			if (username == "0")
				return 0;
			cout << "\nEnter Password: ";
			cin >> password;
			if (!users.count(username)) {
				cout << "Invalid Username!!\n\n";
				continue;
			}
			const User& user = users[username];
			if (user.GetPassword() != password) {
				cout << "Invalid password!!\n\n";
				continue;
			}
			current_user = user;
			break;
		}
		return 1;
	}

	void DoSignUp() {
		string username;
		while (true) {
			cout << "Enter Username (No Spaces): ";
			cin >> username;
			if (users.count(username)) {
				cout << "Username already exists!!\n";
			}
			else break;
		}
		User user;
		user.ReadUser(username, ++last_id);
		users[user.GetUserName()] = user;
		//add user to database
		UpdateDatabase(user);
	}

	void ResetToQuestions(const vector<pair<int, int>>& to_questions) {
		current_user.ResetQuestionsToMe(to_questions);
	}

	void ResetFromQuestions(const vector<int>& from_questions) {
		current_user.ResetQuestionsFromMe(from_questions);
	}

	void ListUsersNamesIds() const {
		for (const auto& user : users) {
			cout << "Username: " << user.second.GetUserName();
			cout << "\t\tUser ID: " << user.second.GetUserId() << '\n';
		}
		cout << '\n';
	}

	pair<int, int>ReadUserId() const {
		int user_id;
		cout << "Enter User Id or -1 to cancel: ";
		cin >> user_id;
		if (user_id == -1)
			return { -1,-1 };
		int allow_an_quest;
		for (const auto& user : users) {
			if (user.second.GetUserId() == user_id)
				return { user_id,user.second.IsAllowAnonymousQuestion() };
		}
		cout << "ID not found!!..Try again\n";
		return ReadUserId();
	}

	void UpdateDatabase(const User& user, const string& file_path = users_file_path") {
		vector<string>data = { user.ToString() };
		WriteFileLines(file_path, data, true);//appends user into users database 
	}
	const User& GetCurrenUser()const {
		return current_user;
	}
};

/***************************************************************
 *                Ask Me System Class                          *
 ***************************************************************/
class AskMeSystem {
	UsersManager users_manager;
	QuestionsManager questions_manager;

	void LoadDatabase(bool fill_user_questions = false) {

		users_manager.LoadDatabase();
		questions_manager.LoadDataBase();

		if (fill_user_questions)
			ResetCurrentUserQuestions();
	}

	void ResetCurrentUserQuestions() {
		const User& current_user = users_manager.GetCurrenUser();

		const auto& to_questions = questions_manager.GetUserFromQuestions(current_user);
		users_manager.ResetToQuestions(to_questions);

		const auto& from_questions = questions_manager.GetUserToQuestions(current_user);
		users_manager.ResetFromQuestions(from_questions);
	}

public:
	void Run() {
		users_manager.AccessSystem(); //login, sign up
		LoadDatabase(false);

		vector<string>menu = { "Print Questions To Me","Print Questions From Me",
			"Answer Question","Delete Question","Ask Question","List System Users",
			"Feed","Logout" };

		const User& current_user = users_manager.GetCurrenUser();
		while (true) {
			int choice = ShowReadMenu(menu);


			LoadDatabase(true);
			cout << "\n\n";
			if (choice == 1) {
				questions_manager.PrintUserToQuestions(users_manager.GetCurrenUser());
				questions_manager.UpdateDatabase();
			}
			else if (choice == 2) {
				questions_manager.PrintUserFromQuestions(users_manager.GetCurrenUser());
				questions_manager.UpdateDatabase();
			}
			else if (choice == 3) {
				questions_manager.AnswerQuestion(current_user);
				questions_manager.UpdateDatabase();
			}
			else if (choice == 4) {
				questions_manager.DeleteQuestion(current_user);
				questions_manager.UpdateDatabase();
			}
			else if (choice == 5) {
				const pair<int, int>& to_user = users_manager.ReadUserId();
				if (to_user.first != -1)
					questions_manager.AskQuestion(current_user, to_user);
				questions_manager.UpdateDatabase();
			}
			else if (choice == 6) {
				users_manager.ListUsersNamesIds();
			}
			else if (choice == 7) {
				questions_manager.ListFeed();
			}
			else break;
		}
		Run();
	}
};

/***************************************************************
 *                        Main Program                         *
 ***************************************************************/
int main()
{
	AskMeSystem service;
	service.Run();
}
