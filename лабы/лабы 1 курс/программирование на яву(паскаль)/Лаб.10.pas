program laba10;
const N: integer = 24;
var q: string;

procedure dec(z: string);//вычитает 1 из переменной string
var error: boolean = false;//присваивание логического значения
    i, j, k, f: integer;
    a, b: real;
    c: array of string = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N');
    d: array of integer = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23);
begin
  f:= length(z) - 1;//length() возвращает целое число, которое указывает на длину строки
  for i:= 1 to length(z) do begin
    for j:= 0 to length(c) - 1 do begin
      if z[i] = c[j] then begin
          b:= d[j] * exp(ln(N) * f);
          f:= f - 1;
          a:= a + b;
          break //выход из цикла
      end
      else 
        if j = length(c) - 1 then
          error:= true;
    end;
  end;
  if error = false then
    writeln(z, '(', N, ') = ', a:0:0, '(10)')
  else
    writeln('Введён недопустимый символ!');
end;

begin
  write('Введите число в 24 системы счисления для перевода в 10-ю: ');
  read(q);
  dec(q);
end.
