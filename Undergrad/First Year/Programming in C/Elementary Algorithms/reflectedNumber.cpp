// It displays the reflected number.

int oglinditNumber(int n)
{
	int oglindit = 0;
	while (n != 0)
	{
		oglindit = oglindit * 10 + n % 10;
		n = n / 10;
	}
	return oglindit;
}

int main()
{
	int n;
	std::cout << "Spune un numar: ";
	std::cin >> n;
	std::cout << "Oglinditul este:" << oglinditNumber(n) << std::endl;

	return 0;
}
