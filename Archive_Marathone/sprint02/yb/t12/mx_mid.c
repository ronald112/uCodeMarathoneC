int mx_mid(int a, int b, int c) { 
  int temp = 0;  
  if (a < b) {
    temp = a;
  }
  else {
    temp = b;
  }
  if (temp > c) {
    return temp;   
  }
  else {
    return c;
  }
}
