#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const size_t VECTOR_SIZE = 10;

void bubbleSort(vector<int>& a) {
	for (size_t i = 0; i <a.size()-1; i++) {
		for (size_t j = 0; j < a.size() - 1-i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void selectionSort(vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		size_t min = i;
		for (size_t j = i; j < a.size(); j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[min], a[i]);

	}
}
void qSort(vector<int>& a) {
	if (a.size() < 2) {
		return;
	}

	else {
		vector <int> less;
		vector <int> greater;
		vector<int> equal;
		size_t pivot = rand()%a.size();

		for (size_t i = 0; i < a.size(); i++) {
			if (a[i] < a[pivot]) {
				less.push_back(a[i]);
			}
			else if (a[i] > a[pivot]){
				greater.push_back(a[i]);
			}
			else {
				equal.push_back(a[i]);
			}
		}
		qSort(less);
		qSort(greater);
		
		a.clear(); 

		a.insert(a.end(), less.begin(), less.end());
		a.insert(a.end(), equal.begin(), equal.end());
		a.insert(a.end(), greater.begin(), greater.end());

	}
	
}
int binSqrt(std::vector<int>& a, int item) {
	if (a.empty()) {
		return -1;
	}
	int temp = a.size() / 2;
	if (a[temp] == item) {
		return temp;
	}
	else if (a[temp] > item) {
		std::vector<int> left(a.begin(), a.begin() + temp);
		return binSqrt(left, item);
	}
	else {
		std::vector<int> right(a.begin() + temp + 1, a.end());
		if (!right.empty()) {
			int result = binSqrt(right, item);
			if (result != -1)
				return result + temp + 1;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	vector<int> vec_1(VECTOR_SIZE);
	vector<int> vec_2(VECTOR_SIZE);
	vector<int> vec_3(VECTOR_SIZE);
	

	//bubbleSort
	cout << "vec_1 - пузырьковая сортировка"<<endl << endl;
	for (size_t i = 0; i <VECTOR_SIZE; i++) {
		vec_1[i] = rand() % 11;
		cout << vec_1[i] << " ";
	}
	cout << endl<< endl;

	bubbleSort(vec_1);

	for (size_t i = 0; i < VECTOR_SIZE; i++) {
		cout << vec_1[i] << " ";
	}
	cout << endl<<endl;


	//selectionSort
	cout << "vec_2 - сортировка вставкой" << endl << endl;
	for (size_t i = 0; i < VECTOR_SIZE; i++) {
		vec_2[i] = rand() % 11;
		cout << vec_2[i] << " ";
	}
	cout << endl << endl;

	selectionSort(vec_2);

	for (size_t i = 0; i < VECTOR_SIZE; i++) {
		cout << vec_2[i] << " ";
	}
	cout << endl<<endl;

	//qsort
	cout << "vec_3 -быстрая сортировка" << endl<<endl;

	for (size_t i = 0; i < VECTOR_SIZE; i++) {
		vec_3[i] = rand() % 11;
		cout << vec_3[i] << " ";
	}
	cout << endl << endl;

	qSort(vec_3);


	for (size_t i = 0; i < VECTOR_SIZE; i++) {
		cout << vec_3[i] << " ";
	}
	cout << endl<<endl;

	//binSqrt
	
	cout << "Введите элемент для бинарного поиска в vec_3"<<endl;
	int temp;
	cin >> temp;
	int result = binSqrt(vec_3, temp);
		if (result == -1) {
			cout << "Элемент не найден" << endl;
		}
		else {
			cout << "Индекс элемента: " << result << endl;
		}
	return 0;
}

