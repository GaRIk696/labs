Program lab_4;
Const x=3.48;
      ε=1E-3;
var S, l, F:real;
    n: integer;
function Fact(n:integer):integer;
var y,Zn:integer;
  begin
    Zn:=1;
    for y:=1 to n do
    begin
      Zn:=Zn*y;
    end;
    Fact:=Zn;
  end;
begin
  S:=0; n:=1;
  l:=((sin(x)/cos(x))/n)/(2*n);
  while l>ε do
  begin
     writeln('S=',S:5:3); writeln('Номер цикла=',n-1);
      F:=Fact(n);
      l:=((sin(x)/cos(x))/n)/(2*F);
      S:=S+1; n:=n+1;
  end;
end.