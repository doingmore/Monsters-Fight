#ifndef RandomNumber_H
#define RandomNumber_H

int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1) };

	return  min + (static_cast<int>((max - min + 1) * (std::rand() * fraction)));
}


#endif // !RandomNumber_H
