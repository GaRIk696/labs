program lab_3;
var
  j:integer;
  result: real;
begin
  for j:=1 to 30 do
begin
  result:=(sqrt((exp(3*ln(j)))+j+3))/((arctan(1/sqrt(1-1*1)))/(j+1));
  writeln('Выражение для j = ', j, ' = ', result:0:2);
  end;
end.