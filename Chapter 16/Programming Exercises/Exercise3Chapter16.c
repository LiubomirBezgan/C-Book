//  Polar coordinates to rectangular coordinates - Exercise3Chapter16.c
//  v1.0
/*  Includes ------------------------------------------------------------------*/
#include <mylib.h>

typedef struct polar {
	double magnitude;
	double angle;
} polar_t;

typedef struct rect {
	double x;
	double y;
} rect_t;

rect_t polar_to_rect(polar_t input);

/*  Main ----------------------------------------------------------------------*/
int main(void)
{
/*  Variables -----------------------------------------------------------------*/
	polar_t polar_in;
	rect_t rect_out;
	
/*  Description ---------------------------------------------------------------*/
	puts("The program is used to convert polar coordinates to rectangular coordinates.\n");
	
/*  Code ----------------------------------------------------------------------*/
	puts("Please enter a magnitude and an angle (in degrees) by separating them with a comma (,):");
	while (2 != scanf("%lf, %lf", &polar_in.magnitude, &polar_in.angle))
	{
		clear_buffer();
		puts("Wrong values. Please try again.");
		puts("\nPlease enter a magnitude and an angle (in degrees) by separating them with a comma (,):");
	}
	printf("r = %g, A = %g\n", polar_in.magnitude, polar_in.angle);
	rect_out = polar_to_rect(polar_in);

	printf("x = %g, y = %g\n", rect_out.x, rect_out.y);


/*  Ending --------------------------------------------------------------------*/
	end('#');
	return 0;
}

rect_t polar_to_rect(polar_t input)
{
	rect_t output;
	output.x = input.magnitude * cos(DEG_TO_RAD(input.angle));
	output.y = input.magnitude * sin(DEG_TO_RAD(input.angle));
	return output;
}