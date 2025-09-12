program lab_6;
var
    i, j: integer;
    sum, term, innerSum: real;
    epsilon: real;
    
function Factorial(n: integer): real;
begin
    if n <= 1 then
        Factorial:=1
    else
        Factorial:=n * Factorial(n-1);
end;
begin
    sum:=0.0;
    epsilon:=0.0001;

    for i:= 1 to 20 do
    begin
        innerSum:= 0;
        j:= 1;

        while true do
        begin
            term:= sqrt(i+j) / Factorial(j);
            innerSum:= innerSum + term;
            j:= j + 1;
            
            if abs(term) < epsilon then
                break;
        end;
        sum:= sum + 2.7 * ln(i) * innerSum;
    end;
    writeln('Результат суммы с точностью до 0.0001: ', sum:0:4);
end.