import "dart:io";

const KRED  = "\x1B[31;1;4m";
const KGRN  = "\x1B[32m";
const KREDU  = "\x1B[31;1;4m";
const KNRM  = "\x1B[0m";

void main() {
  var now = DateTime.now();
  var year = now.year;
  int dayofmonth = now.day;

  int february_days = ((year % 400) == 0 || ((year % 100) != 0 && (year % 4) == 0)) ? 29 : 28;
	var month = [31, february_days, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

  var monthname = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
	var days_in_month = month[now.month - 1];

    printf("    ${monthname[now.month - 1]} - ${year}\n");
    printf("$KREDU Mo Tu We Th Fr Sa Su$KNRM\n");

    for (var x = 1; x < now.weekday; x++){
		  printf("   ");
	  }

    for (var i = 1; i <= days_in_month; i++){

        if (dayofmonth == i)
        {
            printf("$KGRN${i.toString().padLeft(3)}$KNRM");
        }
        else
        {
            printf("${i.toString().padLeft(3)}");
        }
        if ((i + now.weekday - 1) % 7 == 0)
        {
          printf("\n");
        }


    }
	printf("\n");
}

void printf(String value){
  stdout.write(value);
}