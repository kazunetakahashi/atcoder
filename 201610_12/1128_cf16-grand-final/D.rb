@p = gets.chomp.split(" ").map{|i| i.to_f/100}
@q = gets.chomp.split(" ").map{|i| i.to_f/100}

def f(x)
  sum = 0
  for i in 0...6
    sum += [x * @p[i], (1-x) * @q[i]].max
  end
  return sum
end

def g(x)
  sum = 0
  for i in 0...6
    sum += [x * @p[i], (1-x) * @q[i]].max
  end
  return sum
end


kouho = [0, 1]

for i in 0...6
  if @p[i] + @q[i] == 0
    next
  end
  kouho << @q[i]/(@p[i] + @q[i])
end

mini = 10000
mini_x = 0

kouho.each{|x|
  #puts f(x)
  if mini > f(x)
    mini = f(x)
    mini_x = x
  end
  mini = [mini, f(x)].min
}

# p mini_x

printf("%.12f\n", g(mini_x))

