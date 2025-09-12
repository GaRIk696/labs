program lab_5;
var
  x: real;
function K(x: real): real;
begin
  K:= power(10, -x);
end;
function N(x: real): real;
begin
  N:= power(10, sqrt(x));
end;
begin
  writeln('   x    |  10^-x    |  10^(sqrt(x))');
  writeln('---------------------------------');
  x := 0.1;
  while x <= 2 do
  begin
    writeln(x:7:1, ' | ', K(x):0:7, ' | ', N(x):0:7);
    x := x + 0.1;
  end;
end.