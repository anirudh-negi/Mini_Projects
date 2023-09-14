package main

import (
  "fmt"
  "math/rand"
  "time"
)

func main() {
rand.Seed(time.Now().UnixNano())
isHeistOn:=true
eludedGuards:=rand.Intn(100)
if eludedGuards>=50{
  fmt.Println("Looks like you've managed to make it past the guards. Good job, but remember, this is the first step.")
}else {
  isHeistOn=false
  fmt.Println("Plan a better disguise next time?")
}
openedVault:=rand.Intn(100)
if isHeistOn && openedVault>=70{
  fmt.Println("Grab and GO!")
} else if isHeistOn && openedVault<70{
  isHeistOn=false
  fmt.Println("Plan a better disguise next time.What's the combo to this lock again??")
}
leftSafely:=rand.Intn(5)
if isHeistOn{
  switch leftSafely{
    case 0:
      isHeistOn=false
      fmt.Println("Failed Heist! You tripped an alarm")
    case 1:
     isHeistOn=true
     fmt.Println("Start the gateaway car!")
    case 2:
      isHeistOn=false
      fmt.Println("Failed Heist! Who woke the dogs")
      case 3:
      isHeistOn=false
      fmt.Println("Failed Heist! Fingerprint scanner is not taking any fingerprints")
      case 4:
      isHeistOn=false
      fmt.Println("Failed Heist!No one carried the bags")
     default:
     isHeistOn=true
     fmt.Println("Start the gateaway car!")

}
}
if isHeistOn{
  amtStolen:=1000+rand.Intn(1000000)
  fmt.Println("Amount Stolen=",amtStolen)
}
}

