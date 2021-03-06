#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
	string money_;
	string money_temp_;
public:
	Bank();
	~Bank();
	void Check(const string&);
	void Transfer(const string&);
};

int main(void)
{	
	Bank Tester;
	//string TestMoney = "12,345,678,901,234원"; // Test Case 1 : 정상금액
	//string TestMoney = "12,345,678,901,234,000원"; // Test Case 2 : 초과금액
	//string TestMoney = "010,000,000,000,000원"; // Test Case 3 : 0으로 시작하는 경우
	string TestMoney = "100,000,000,000,000원"; // Test Case 4 : 백조원

	Tester.Check(TestMoney);
	Tester.Transfer(TestMoney);

	return 0;
}

Bank::Bank()
{
	cout << "이체금액을 입력해 주세요." << endl;
}

Bank::~Bank()
{
	cout << "이체가 완료되었습니다." << endl;
}

// 입력 받은 금액이 1원 ~ 100조원 사이의 값인지 검사하는 멤버 함수
void Bank::Check(const string& money)
{
	money_ = money;

	// 입력 받은 금액에서 '원'글자를 제거함
	money_ = money_.erase(money_.find("원"));

	// 입력 받은 금액에서 '콤마(,)'를 제거함
	for(int i = 0; i < money_.length(); i++)
	{
		if(money_[i] != ',')
		{
			money_temp_ += money_[i];
		}
	}

	if (money_temp_[0] == '0')
	{
		cout << "금액이 0으로 시작할 수는 없습니다." << endl;
		exit(0);
	}
	else if (money_temp_.length() > 14)
	{
		if (money_temp_ == "100000000000000") { }
		else
		{
			cout << "1원 ~ 100조원 사이의 금액을 입력해 주세요." << endl;
			exit(0);
		}
	}
	else { }
}

// 입력 받은 금액을 한글로 변환하는 멤버 함수
void Bank::Transfer(const string& money)
{
	money_ = money;
	money_temp_ = "";

	// 입력 받은 금액에서 '원'글자를 제거함
	money_ = money_.erase(money_.find("원"));

	// 입력 받은 금액에서 '콤마(,)'를 제거함
	for(int i = 0; i < money_.length(); i++)
	{
		if(money_[i] != ',')
		{
			money_temp_ += money_[i];
		}
	}

	money_ = "";

	// 입력 받은 금액에 '조, 억, 만, 천, 백, 십' 단위를 붙임
	for(int i = 0; i < money_temp_.length(); i++)
	{
		if (((money_temp_.length() - i) % 12 == 1) && (money_temp_.length() - i != 1))
		{
			money_ += money_temp_[i];
			money_ += "조 ";
		}
		else if (((money_temp_.length() - i) % 8 == 1) && (money_temp_.length() - i != 1))
		{
			if ((money_temp_[i] == '0')
				&& (money_temp_[i - 1] == '0')
				&& (money_temp_[i - 2] == '0')
				&& (money_temp_[i - 3] == '0'))
			{
				money_ += money_temp_[i];
			}
			else
			{
				money_ += money_temp_[i];
				money_ += "억 ";
			}
		}
		else if (((money_temp_.length() - i) % 4 == 1) && (money_temp_.length() - i != 1))
		{
			if ((money_temp_[i] == '0')
				&& (money_temp_[i - 1] == '0')
				&& (money_temp_[i - 2] == '0')
				&& (money_temp_[i - 3] == '0'))
			{
				money_ += money_temp_[i];
			}
			else
			{
				money_ += money_temp_[i];
				money_ += "만 ";
			}
		}
		else if (((money_temp_.length() - i) % 4 == 0) && (money_temp_[money_temp_.length() - i] != '0'))
		{
			money_ += money_temp_[i];
			money_ += "천";
		}
		else if (((money_temp_.length() - i) % 4 == 3) && (money_temp_[money_temp_.length() - i] != '0'))
		{
			money_ += money_temp_[i];
			money_ += "백";
		}
		else if (((money_temp_.length() - i) % 4 == 2) && (money_temp_[money_temp_.length() - i] != '0'))
		{
			money_ += money_temp_[i];
			money_ += "십";
		}
		else
		{
			money_ += money_temp_[i];
		}
	}

	money_temp_ = money_;
	money_ = "";

	// 입력 받은 금액의 '숫자'를 '한글'로 변환함
	for(int j = 0; j < money_temp_.length(); j++)
	{
		if ((money_temp_[j] == '1') || (money_temp_[j] == '0'))
		{
			money_ += "";
		}
		else if ((money_temp_[j] == '2'))
		{
			money_ += "이";
		}
		else if ((money_temp_[j] == '3'))
		{
			money_ += "삼";
		}
		else if ((money_temp_[j] == '4'))
		{
			money_ += "사";
		}
		else if ((money_temp_[j] == '5'))
		{
			money_ += "오";
		}
		else if ((money_temp_[j] == '6'))
		{
			money_ += "육";
		}
		else if ((money_temp_[j] == '7'))
		{
			money_ += "칠";
		}
		else if ((money_temp_[j] == '8'))
		{
			money_ += "팔";
		}
		else if ((money_temp_[j] == '9'))
		{
			money_ += "구";
		}	
		else
		{
			money_ += money_temp_[j];
		}
	}

	money_ += "원";

	cout << money_ << endl;
}
