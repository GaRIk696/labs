program lab_9;
type m=array [1..4] of real;

var
A:m:=(3, 0, -1, 5);
B:m:=(8, 4.2, 8.8, 5.5);
C:m:=(-1, 6, 1.8, 6.7);

procedure F(x, y: m);
  var i, j, iC, jC: integer;
    promRes: real;
  begin
    for i:=1 to 4 do begin
      write('');
      for j:= 1 to 4 do begin
        iC := i;
        jC := j;
        promRes:= sqrt((x[i]+jC)/(y[j]+iC)+5);
        write(promRes:5:2);
      end;
      writeln('|':2);
    end;
    writeln();
  end;

begin
  writeln('Массив X:');
  F(A,B);
  writeln('Массив Y:');
  F(A,C);
  writeln('Массиы Z:');
  F(B,C);
end.