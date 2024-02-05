echo "Enter two Numbers"
read num1
read num2
if(($num1>$num2))
 then
   echo "$num1 is greater"
 elif(($num1==$num2))
  then
   echo "Numbers are equal"
   
  else
    
     echo "$num2 is greater"
    
  fi      
