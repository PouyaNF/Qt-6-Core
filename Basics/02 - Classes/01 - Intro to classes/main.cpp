	/*
		intro to classes
		We want to create objects  from blueprints
	*/


	#include <QCoreApplication>
	#include "animal.h"

	int main(int argc, char *argv[])
	{
		QCoreApplication a(argc, argv);

		Animal cat;
		Animal dog;
		Animal fish;

		cat.setObjectName("Kitty");
		dog.setObjectName("Fido");
		fish.setObjectName("FishStick");

		cat.speak("meow");
		dog.speak("bark");
		fish.speak("blablabla");

		return a.exec();
	}
