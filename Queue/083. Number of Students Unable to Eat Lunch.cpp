class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
     //   //my approach but TLE
     //    queue<int>q; 
     //    for(int i=0;i<students.size();i++){
     //        q.push(students[i]);
     //    }
     //    int i=0;
     //    while(i<sandwiches.size()){
     //        if(q.front()==sandwiches[i]){
     //            i++;
     //            q.pop();
     //        }
     //        else{
     //            q.push(q.front());
     //            q.pop();
     //        }
     //    }
     //    return q.size();
     // }
        
        //goood one
	// int student_count = students.size(), circular_stu=0, square_stu=0;
	// for(int i=0; i<students.size(); i++){
	// 	if(students[i] == 0){circular_stu++;}
	// 	else{square_stu++;}
	// }
	// for(int i=0; i<sandwiches.size(); i++){
	// 	if(sandwiches[i] == 0){
	// 		if(circular_stu > 0){
	// 			student_count--;  // because he'll take it and leave the line.
	// 			circular_stu--;    // circular student is also gone.
	// 		}
	// 		else{return student_count;}
	// 	}
	// 	else{
	// 		if(square_stu > 0){
	// 			student_count--;
	// 			square_stu--;
	// 		}
	// 		else{return student_count;}
	// 	}
	// }
	// return student_count;
	// }
    
     queue<int>q;
        //pushingb all stud in q
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int count=0,i=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            //if student doesnt match with the sandwich push that student at end again and also count it
            if(curr!=sandwiches[i]){
                count++;
                q.push(curr);
            }
            //if both matches then we move the index of sandwich to check fursther
            else{
                i++;
                count=0;//starting again if index matches
            }
            if(count==q.size()) break;//at any point count = q.size means the elemnts present are not matching 
        }
        return q.size();
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
