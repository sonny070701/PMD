bool isBinary(char* string){

  char texto; 
  while(*string != '\0'){
    if ((*string!='1')||(*string!='0')){
      texto = 0; 
      break;
    }
    else{
      texto = 1; 
      string++;
    }
    return texto; 
  }
}
