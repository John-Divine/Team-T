#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
int time_tocover_dist(int dist,int tdist,int sdist,int tbduration,int tcool){
	int turbo=tbduration,cool,cdist=0,time=0,i;
	while(cdist<=dist){
		if(turbo!=0){
			cdist=cdist+tdist;
			time=time+1;
			turbo=turbo-1;
			if(turbo==0){
				cool=tcool;
			}
		}
		else{
			cdist=cdist+tdist;
			time=time+1;
			cool=cool-1;
			if(cool==0){
				turbo=tbduration;
			}
		}
	}
	return time;
}


int main(){
	int test_case,tdist,sdist,tbduration,tcool,ncars,car_detail[5];
	FILE *file_ptr,*fp;
	char filename[]="input.txt";
	fp = fopen("Result.txt", "w+");
	//open file
	if ((file_ptr = fopen(filename, "r")) != NULL)
	{
		// read data from file
		fscanf(file_ptr, "%d\n", &test_case);

		int road_dist;
		for(int i =0;i<test_case;i++){
		fscanf(file_ptr, "%d %d\n", &road_dist, &ncars);
		int t_cmplt[ncars],cnt=0,min;
		for(int k=0;k<ncars;k++){
			fscanf(file_ptr, "%d  %d %d %d %d\n", &car_detail[0],&car_detail[1],&car_detail[2],&car_detail[3],&car_detail[4]);

			t_cmplt[cnt]= time_tocover_dist(road_dist,car_detail[2],car_detail[1],car_detail[4],car_detail[3]);
			cnt=cnt+1;

				}
		for(int j=0;j<cnt-1;j++){
			if(t_cmplt[j]<t_cmplt[j+1]){
				min=j;
			}
			else if(t_cmplt[j]==t_cmplt[j+1]){
				min=j;
			}
			else{
				min=j+1;
			}
	}
		fprintf(fp, "Case #%d: %d %d %d\n",i,min,t_cmplt[min],road_dist); // Write winner for test case row
		}

}
	// close file
	fclose(file_ptr);
	fclose(fp);

	return 0;
}
