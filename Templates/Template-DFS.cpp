//Depth First Search(DFS)
void dfs(){
	if(/*Terminal State*/){
		/*Do*/
		return;
	}
	if(/*Transgression or Illegality*/)
		return;
	if(/*Special State*/){
		/*Cut*/
		return;
	}
	for(/*Extended Mode*/){
		if(/*The State Reached by Extension is Legal*/){
			/*Retouching Operation*/
			/*Tag*/
			dfs();
			/*Restore Tag*/
		}
	}
}
