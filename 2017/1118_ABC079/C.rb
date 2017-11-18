n = gets.chomp

def dfs(s, i)
  if i == 3
    if eval(s) == 7
      puts s + "=7"
      exit
    end
  else
    puts s[0...2*i+1] + '+' + s[2*i+1...s.size]
    dfs(s[0...2*i+1] + '+' + s[2*i+1...s.size], i+1)
    dfs(s[0...2*i+1] + '-' + s[2*i+1...s.size], i+1)
  end
end

dfs(n, 0)
