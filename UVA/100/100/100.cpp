#include <queue>
#include<algorithm>
#include <iostream>

int main() {
	unsigned int _num1, _num2,cont,temp,n;


	while (scanf("%d", &n) != EOF)
	{	
		temp = 0;
		_num1= n;
		scanf("%d", &n);
		_num2 = n;
		cont = _num2;

		while (cont > _num1) {
			if (cont & 1) { cont = 3 * cont + 1; }
			else { cont = cont / 2; }
			temp++;
		}
	

		printf("%d %d %d", _num1, _num2, temp);
	}


	return 0;
}