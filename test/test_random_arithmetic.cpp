//
//
// Created by shiby on 22-9-20.

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;

typedef double elementType;

int random_number(int minInt = 0, int maxInt = 100);

float find_maximum(const float *list, int length);

float find_minimum(const float *list, int length);

float find_average(const float *list, int length);


enum examRank {
    easy,
    hard
};

//class Expression {
//private:
//    int num1;
//    int num2;
//    char sign;
//    elementType result;
//
//    elementType calculate() const {
//        switch (sign) {
//            case '+':
//                return num1 + num2;
//            case '-':
//                return num1 - num2;
//            case '*':
//                return num1 * num2;
//            default:
//                return num1 / num2;
//        }
//    }
//
//    char random_sign(examRank rank) const {
//        int num = (rank == easy ? 2 : 4);
//        switch (random_number(0, num)) {
//            case 0:
//                return '+';
//            case 1:
//                return '-';
//            case 2:
//                return '*';
//            default:
//                return '/';
//        }
//    }
//
//public:
//    Expression(int n1, int n2, char sign)
//            : num1(n1), num2(n2), sign(sign), result(0) {}
//
//    explicit Expression(int maxNum = 100, examRank rank = easy) :
//            num1(random_number(0, maxNum)),
//            num2(random_number(0, int(maxNum - num1))),
//            sign(random_sign(rank)),
//            result(calculate()) {}
//
//    friend ostream &operator<<(ostream &os, const Expression &expr) {
//        cout << expr.num1 << expr.sign << expr.num2 << "=";
//        return os;
//    }
//
//    int check(elementType r) const {
//        return r == this->result ? 1 : 0;
//    }
//
//    elementType get_result() const {
//        return this->result;
//    }
//
//};

typedef struct expression {
    string str;
    elementType result{};
    string complete_expr;
} Expression;


Expression random_expression(int maxNum, examRank rank) {
    const char sign_list[4] = {'+', '-', '*', '\\'};
    int num1 = random_number(0, maxNum);
    int num2 = random_number(0, maxNum);
    char sign = sign_list[random_number(0, (rank == easy ? 2 : 4))];
    elementType result;
    switch (sign) {
        case '+': {
            result = num1 + num2;
            break;
        }
        case '-': {
            result = num1 - num2;
            break;
        }
        case '*': {
            result = num1 * num2;
            break;
        }
        default:
            result = double(num1) / num2;
    }


    string s = to_string(num1) + " " + sign + " " + to_string(num2) + " = ";
    ostringstream oss;
    oss << setprecision(4) << result;
    string s2 = s + oss.str();
    Expression e = {s, result, s2};
    return e;
}


typedef struct examination {
    Expression *exp;
    int count_exam;
    float *use_time;
    elementType *result_list;
    examRank rank;
} Examination;

void print_examination(const Examination &exam) {
    int count_correct_num = 0;
    int count_incorrect_num = 0;
    cout << endl;

    cout << "Total： " << exam.count_exam << endl;

    for (int i = 0; i < exam.count_exam; ++i) {
        if (exam.exp[i].result != exam.result_list[i]) {
            cout << exam.exp[i].complete_expr << " (Incorrect answer: " << exam.result_list[i] << ")" << endl;
            count_incorrect_num++;
        } else {
            count_correct_num++;
        }
    }
    cout << endl;
    cout << "Correct number of expression: " << count_correct_num << endl;
    cout << "Incorrect number of expression: " << count_incorrect_num << "\n" << endl;


    cout.precision(4);
    cout << "Minimum cost time: " << find_minimum(exam.use_time, exam.count_exam) << endl;
    cout << "Maximum cost time: " << find_maximum(exam.use_time, exam.count_exam) << endl;
    cout << "Average cost time: " << find_average(exam.use_time, exam.count_exam) << endl;


}

int random_number(int minInt, int maxInt) {
    return rand() % maxInt;
}

void clean_stdin() {
    while (getchar() != '\n')
        continue;
}

double get_ctime() {
    return chrono::system_clock::now().time_since_epoch().count() / 1e9;
}

float find_minimum(const float *list, int length) {
    float minimum = *list;
    for (int i = 0; i < length; ++i) {
        if (list[i] < minimum)
            minimum = list[i];
    }
    return minimum;
}


float find_maximum(const float *list, int length) {
    float maximum = *list;
    for (int i = 0; i < length; ++i) {
        if (list[i] > maximum)
            maximum = list[i];
    }
    return maximum;
}

float find_average(const float *list, int length) {
    float total = 0.0f;
    for (int i = 0; i < length; ++i) {
        total += list[i];
    }
    return total / float(length);
}

int main() {
    srand((unsigned int) time(nullptr));

    Examination exam;
    double t1;
    int count_expression;
    int exam_rank;
    cout << "请输入题目个数：";
    cin >> count_expression;
    clean_stdin();
    cout << "请输入题目难度0-easy, 1-hard: ";
    cin >> exam_rank;

    elementType result_list[count_expression];
    Expression expression_list[count_expression];
    float use_time_list[count_expression];
    exam.exp = expression_list;
    exam.count_exam = count_expression;
    exam.result_list = result_list;
    exam.use_time = use_time_list;
    exam.rank = (exam_rank == easy ? easy : hard);
    for (int i = 0; i < count_expression; ++i) {
        expression_list[i] = random_expression(100, exam.rank);
    }


    for (int i = 0; i < count_expression; ++i) {
        cout << expression_list[i].str;
        t1 = get_ctime();
        while (true) {
            cin >> result_list[i];
            if (!cin.fail() && cin.get() == '\n')
                break;
            clean_stdin(); // failed buffer[-1]
            cin.clear();
            cin.sync();
            cout << "Invalid input." << endl;
            cout << expression_list[i].str;
        }
        use_time_list[i] = float(get_ctime() - t1);
    }
    print_examination(exam);
}