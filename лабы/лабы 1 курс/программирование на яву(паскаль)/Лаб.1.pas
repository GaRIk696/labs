program lab1;
  var p,q,L:real;
  const w=0.28;
begin
  q:=1+(1/sqr(w));
  p:=ln(w*q)/ln(10);
  
  L:=arcsin(w*((p*q)/(p+q+1)));
  write(L:10:3);
end.