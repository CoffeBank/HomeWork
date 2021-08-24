int M = 0;
struct Telefon {
	unsigned long long int Nomber;
	char Name[10];
} T[10];

void In(void) {
	printf("Введите имя абонента %d по счету: ", M);
	scanf("%s", &T[M].Name);
	printf("Введите номер телефона %d абонента: ", M);
	scanf("%lld", &T[M].Nomber);
	M++;
}

void Out(void) {
	int n = 0;
	printf("Введите номер по счету для вывода на экран: (нажми 99 для вывода всех абонентов)  ");
	scanf("%d", &n);
	if (n == 99) {
		for (int i = 0; i < M; i++) {
			if (T[i].Nomber == 0) 
			{ 
				printf("В %d строчке удаленный пользователь\n", i); 
				continue; 
			}
			printf("Имя абононента %d: %s\n", i, T[i].Name);
			printf("Номер телефона: %lld\n", T[i].Nomber);
		}
		printf("\nВыведены все пользователи!\n");
	}
	else {
		int i = 0;
		if (T[n].Nomber == 0) 
		{
			printf("В %d строчке удаленный абонент\n", n); 
			i = 1; 
		}
		if (i == 0) {
			printf("Имя абонента %d: %s\n", i, T[i].Name);
			printf("Номер телефона: %lld\n", T[i].Nomber);
		}
		i = 0;
	}
}

void Clear() {
	for (int i = 0; i < M; i++)
		T[i].Nomber = 0;
	printf("Телефонная книга очищена!\n");
}

void Delete() {
	int i;
	printf("Введите номер по счету для удаления из книги:");
	scanf("%d", &i);
	T[i].Nomber = 0;
	printf("Номер успешно удален\n");
}


void FindCall(char call[10]) {
	int m = 0;
	for (int i = 0; i < M; i++)
	{
		if (strcmp(call, T[i].Name) == 0)
		{
			printf("Это абонент под именем %s с номером %lld\n",T[i].Name, T[i].Nomber);
			m++;
		}
	}

	if (m == 0) 
		printf("Этот абонент не найден\n");
	
}

void Edit() {
	int i;
	printf("Введите номер пользователя:");
	scanf("%d", &i);
	printf("Введите новое имя пользователя: ");
	scanf("%s", &T[i].Name);
	printf("Введите новый номер телефона: ");
	scanf("%lld", &T[i].Nomber);
}


void Bardak() {
	system("@cls||clear");
}