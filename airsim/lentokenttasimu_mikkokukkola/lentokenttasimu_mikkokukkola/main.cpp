// Mikko Kukkola
// TAMK, 2014

#include "Runway.h"
#include "Random.h"

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Runway is idle." << endl;
}

void initialize(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate)
	/*
	Pre:  The user specifies the number of time units in the simulation,
	the maximal queue sizes permitted,
	and the expected arrival and departure rates for the airport.
	Post: The program prints instructions and initializes the parameters
	end_time, queue_limit, arrival_rate, and departure_rate to
	the specified values.
	Uses: utility function user_says_yes
	*/

{
	cout << "This program simulates an airport with only one runway." << endl
		<< "One plane can land or depart in each unit of time." << endl;
	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time? " << flush;
	cin >> queue_limit;

	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;

	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;

		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This airport will become saturated. " << endl;

	} while (!acceptable);
}

bool move_plane(Runway & current_runway, int current_time) {
	Plane moving_plane;
	bool free;
	switch (current_runway.activity(current_time, moving_plane)) {
		//  Let at most one Plane onto the Runway at current_time.   
	case land:
		moving_plane.land(current_time);
		free = false;
		break;
	case take_off:
		moving_plane.fly(current_time);
		free = false;
		break;
	case idle:
		run_idle(current_time);
		free = true;
	}
	return free;
}

void main_1()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
run, the expected number of planes arriving, the expected number
of planes departing per time interval, and the
maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
the status of the runway at each time interval, and prints out a
summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;
	Runway small_airport(queue_limit);
	for (int current_time = 0; current_time < end_time; current_time++) //  loop over time intervals
	{
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++)
		{
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++)
		{
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane;
		switch (small_airport.activity(current_time, moving_plane))
		{
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			moving_plane.land(current_time);
			break;
		case take_off:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}
	}
	small_airport.shut_down(end_time);
}

void main_2()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
run, the expected number of planes arriving, the expected number
of planes departing per time interval, and the
maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
the status of the runway at each time interval, and prints out a
summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
	int end_time;            //  time to run simulation   
	int queue_limit;         //  size of Runway queues   
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;

	Runway landing(queue_limit);
	Runway takeoff(queue_limit);

	for (int current_time = 0; current_time < end_time; current_time++)
	{

		int number_arrivals = variable.poisson(arrival_rate);
		for (int i = 0; i < number_arrivals; i++)
		{
			Plane current_plane(flight_number++, current_time, arriving);

			if (landing.can_land(current_plane) != success)
			{
				current_plane.refuse();
			}
		}

		int number_departures = variable.poisson(departure_rate);
		for (int j = 0; j < number_departures; j++)
		{
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff.can_depart(current_plane) != success)
			{
				current_plane.refuse();
			}
		}

		move_plane(landing, current_time);
		move_plane(takeoff, current_time);

	}

	//  statistics 
	cout << endl << "Statistics for landing runway:" << endl;
	landing.shut_down(end_time);

	cout << endl << "Statistics for takeoff runway:" << endl;
	takeoff.shut_down(end_time);
}

void main_3()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
run, the expected number of planes arriving, the expected number
of planes departing per time interval, and the
maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
the status of the runway at each time interval, and prints out a
summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
	int end_time;            //  time to run simulation   
	int queue_limit;         //  size of Runway queues   
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;

	Runway landing(queue_limit);
	Runway takeoff(queue_limit);

	for (int current_time = 0; current_time < end_time; current_time++)
	{

		int number_arrivals = variable.poisson(arrival_rate);
		for (int i = 0; i < number_arrivals; i++)
		{
			Plane current_plane(flight_number++, current_time, arriving);

			if (landing.can_land(current_plane) != success)
			{
				current_plane.refuse();
			}
		}

		int number_departures = variable.poisson(departure_rate);
		for (int j = 0; j < number_departures; j++)
		{
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff.can_depart(current_plane) != success)
			{
				current_plane.refuse();
			}
		}
		bool runway_free_L = move_plane(landing, current_time);
		bool runway_free_D = move_plane(takeoff, current_time);
		if (runway_free_L == true)
		{
			landing.can_depart(takeoff.return_plane(2));
			// landing.append_plane(2, takeoff.return_plane(2));
			move_plane(landing, current_time);
		}
		else if (runway_free_D == true)
		{
			takeoff.can_land(landing.return_plane(1));
			// takeoff.append_plane(1, landing.return_plane(1));
			move_plane(takeoff, current_time);
		}
	}

	cout << endl << "Statistics for landing runway:" << endl;
	landing.shut_down(end_time);

	cout << endl << "Statistics for takeoff runway:" << endl;
	takeoff.shut_down(end_time);
}			

void main_4()
{
	int end_time;
	int queue_limit;
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable;

	Runway landing(queue_limit);
	Runway takeoff(queue_limit);
	Runway overflow(queue_limit);

	for (int current_time = 0; current_time < end_time; current_time++)
	{

		int number_arrivals = variable.poisson(arrival_rate);
		for (int i = 0; i < number_arrivals; i++)
		{
			Plane current_plane(flight_number++, current_time, arriving);

			if (landing.can_land(current_plane) != success)
			{
				if (overflow.can_land(current_plane) != success)
					current_plane.refuse();
			}
		}

		int number_departures = variable.poisson(departure_rate);
		for (int j = 0; j < number_departures; j++)
		{
			Plane current_plane(flight_number++, current_time, departing);
			if (takeoff.can_depart(current_plane) != success)
			{
				// etuoikeus laskeutuville koneille
				if ((overflow.can_depart(current_plane) != success) || (overflow.arrival_size() > 0))
					current_plane.refuse();
			}
		}

		move_plane(landing, current_time);
		move_plane(takeoff, current_time);
		move_plane(overflow, current_time);

	}

	// Lopputilastot
	cout << endl << "Statistics for landing runway:" << endl;
	landing.shut_down(end_time);

	cout << endl << "Statistics for takeoff runway:" << endl;
	takeoff.shut_down(end_time);

	cout << endl << "Statistics for overflow runway:" << endl;
	overflow.shut_down(end_time);
}

int main()
{
	int version;
	cout << "Minkä version haluat ajaa (1-4)? Poistu syottamalla 0";
	cin >> version;
	switch (version){
	case 1:
		main_1();
	case 2:
		main_2();
	case 3:
		main_3();
	case 4:
		main_4();
	case 0:
		break;
	}

	system("pause");
	return 0;
}