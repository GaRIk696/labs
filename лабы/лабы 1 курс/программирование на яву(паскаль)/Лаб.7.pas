program lab_7;
const MAX_SIZE = 16;
type
    TCharArray = array[1..MAX_SIZE] of Char;
var
    Arr: TCharArray;
    i, j, k: integer;
    tmp: Char;
    swapped: boolean;

procedure ShakerSort(var A: TCharArray);
var
    Left, Right, i: integer;
begin
    Left := 1;
    Right := MAX_SIZE;
    repeat
        swapped := false;
        
        for i := Left to Right - 1 do
        begin
            if A[i] > A[i + 1] then
            begin
                tmp := A[i];
                A[i] := A[i + 1];
                A[i + 1] := tmp;
                swapped := true;
            end;
        end;
        Dec(Right);

        for i := Right downto Left + 1 do
        begin
            if A[i] < A[i - 1] then
            begin
                tmp := A[i];
                A[i] := A[i - 1];
                A[i - 1] := tmp;
                swapped := true;
            end;
        end;
        Inc(Left);
    until not swapped;
end;
begin
    writeln('Введите элементы для сортировки (не более ', MAX_SIZE, '): ');
    for i := 1 to MAX_SIZE do
    begin
        readln(Arr[i]);
    end;
    ShakerSort(Arr);
    writeln('Отсортированный массив:');
    for i := 1 to MAX_SIZE do
    begin
        write(Arr[i], ' ');
    end;
end.