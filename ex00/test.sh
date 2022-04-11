NAME=$1

array=(
  "'c'"
  "42"
  "-42"
  "0"
  "0.0f"
  "42.0f"
  "-4.2f"
  "4.2f"
  "-42.5f"
  "-inff"
  "+inff"
  "nanf"
  "0.0"
  "-4.2"
  "4.242"
  "-inf"
  "+inf"
  "nan"
)

for i in ${!array[@]};
do
  TESTCASE=${array[$i]}
  echo --- "$TESTCASE" ---
  ./$NAME "$TESTCASE"
done
