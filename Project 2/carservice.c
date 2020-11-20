//Thomas Davidson
//This is my car service price calculator. I built
//it in a very primitive way since I figured I could
//utilize copy and paste effectively.
//It determines which services to offer based off vehicle choice
//and current mileage, then calculates price with tax.
#include <stdio.h>
#include <string.h>
int main (){

int currentMileage, type;
double total = 0;
  char choice[1] = "a";
  char bigYes[] = "Y";
  char littleYes [] = "y";
  char bigNo[] = "N";
  char littleNo [] = "n";
printf("Enter 1-2 for vehicle type\n");
printf("1. Car\n");
printf("2. Truck\n");
printf("What is your choice? ");
scanf("%d", &type);
if ((type != 1) && (type != 2)){
  printf("Invalid choice entered.\n");
  printf("Goodbye.\n");
  return 0;
}
printf("\nEnter your current mileage: ");
scanf("%d", &currentMileage);
if ((currentMileage < 0) || (currentMileage > 500000)){
  printf("Invalid choice entered.\n");
  printf("Goodbye.\n");
  return 0;
}
printf("\n");
//begin the logic
if (type == 1){ //beginning of Car options
  if ((currentMileage >= 0) && (currentMileage <= 19999)){
    printf("\nWhich services should be performed today?\n");
    printf("Please answer Y/y or N/n\n\n");
    printf("Oil Change $89.95? ");
    scanf("%s", choice); //don't do /n after in same statement
      if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
        total = total + 89.95;
        }
        else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
          total = total + 0;
        }
        else{
          printf("Invalid choice entered.\n");
          printf("Goodbye.\n");
          return 0;
        }
      }
      else if ((currentMileage >= 20000) && (currentMileage <= 34999)){
        printf("Which services should be performed today?\n");
        printf("Please answer Y/y or N/n\n\n");
        printf("Oil Change $89.95? ");
        scanf("%s", choice); //don't do /n after in same statement
          if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
            total = total + 89.95;
            }
            else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
              total = total + 0;
            }
            else{
              printf("Invalid choice entered.\n");
              printf("Goodbye.\n");
              return 0;
            }
            printf("Tire alignment $50.00? ");
            scanf("%s", choice); //don't do /n after in same statement
              if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                total = total + 50.00;
                }
                else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                  total = total + 0;
                }
                else{
                  printf("Invalid choice entered.\n");
                  printf("Goodbye.\n");
                  return 0;
                }
          }
          else if ((currentMileage >= 35000) && (currentMileage <= 49999)){
            printf("Which services should be performed today?\n");
            printf("Please answer Y/y or N/n\n\n");

            printf("Oil Change $89.95? ");
            scanf("%s", choice); //don't do /n after in same statement
              if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                total = total + 89.95;
                }
                else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                  total = total + 0;
                }
                else{
                  printf("Invalid choice entered.\n");
                  printf("Goodbye.\n");
                  return 0;
                }
                printf("Tire alignment $50.00? ");
                scanf("%s", choice); //don't do /n after in same statement
                  if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                    total = total + 50.00;
                    }
                    else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                      total = total + 0;
                    }
                    else{
                      printf("Invalid choice entered.\n");
                      printf("Goodbye.\n");
                      return 0;
                    }
                    printf("Windshield wiper blades $45.95? ");
                    scanf("%s", choice); //don't do /n after in same statement
                      if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                        total = total + 45.95;
                        }
                        else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                          total = total + 0;
                        }
                        else{
                          printf("Invalid choice entered.\n");
                          printf("Goodbye.\n");
                          return 0;
                        }
}
              else if ((currentMileage >= 50000) && (currentMileage <= 64999)){
                printf("Which services should be performed today?\n");
                printf("Please answer Y/y or N/n\n\n");

                printf("Oil Change $89.95? ");
                scanf("%s", choice); //don't do /n after in same statement
                  if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                    total = total + 89.95;
                    }
                    else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                      total = total + 0;
                    }
                    else{
                      printf("Invalid choice entered.\n");
                      printf("Goodbye.\n");
                      return 0;
                    }
                    printf("Tire alignment $50.00? ");
                    scanf("%s", choice); //don't do /n after in same statement
                      if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                        total = total + 50.00;
                        }
                        else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                          total = total + 0;
                        }
                        else{
                          printf("Invalid choice entered.\n");
                          printf("Goodbye.\n");
                          return 0;
                        }
}
else if ((currentMileage >= 65000) && (currentMileage <= 79999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $89.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 89.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $50.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 50.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Windshield wiper blades $45.95? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 45.95;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Engine air filter $30.50? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 30.50;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
                  printf("Brake fluid $73.00? ");
                  scanf("%s", choice); //don't do /n after in same statement
                    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                      total = total + 73.00;
                      }
                      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                        total = total + 0;
                      }
                      else{
                        printf("Invalid choice entered.\n");
                        printf("Goodbye.\n");
                        return 0;
                      }
}
else if ((currentMileage >= 80000) && (currentMileage <= 99999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $89.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 89.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $50.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 50.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Timing belt $245.00? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 245.00;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Transmission fluid $75.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 75.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}
else if ((currentMileage >= 100000) && (currentMileage <= 114999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $89.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 89.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $50.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 50.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Engine air filter $30.50? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 30.50;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Brake fluid $73.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 73.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}
else if ((currentMileage >= 115000) && (currentMileage <= 500000)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $89.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 89.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $50.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 50.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Windshield wiper blades $45.95? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 45.95;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Timing belt $245.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 245.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}
} //end of cars options
//beginning of truck options
else if (type == 2){
  if ((currentMileage >= 0) && (currentMileage <= 19999)){
    printf("\nWhich services should be performed today?\n");
    printf("Please answer Y/y or N/n\n\n");
    printf("Oil Change $119.95? ");
    scanf("%s", choice); //don't do /n after in same statement
      if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
        total = total + 119.95;
        }
        else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
          total = total + 0;
        }
        else{
          printf("Invalid choice entered.\n");
          printf("Goodbye.\n");
          return 0;
        }
      }
      else if ((currentMileage >= 20000) && (currentMileage <= 34999)){
        printf("Which services should be performed today?\n");
        printf("Please answer Y/y or N/n\n\n");
        printf("Oil Change $119.95? ");
        scanf("%s", choice); //don't do /n after in same statement
          if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
            total = total + 119.95;
            }
            else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
              total = total + 0;
            }
            else{
              printf("Invalid choice entered.\n");
              printf("Goodbye.\n");
              return 0;
            }
            printf("Tire alignment $100.00? ");
            scanf("%s", choice); //don't do /n after in same statement
              if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                total = total + 100.00;
                }
                else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                  total = total + 0;
                }
                else{
                  printf("Invalid choice entered.\n");
                  printf("Goodbye.\n");
                  return 0;
                }
          }

          else if ((currentMileage >= 35000) && (currentMileage <= 49999)){
            printf("Which services should be performed today?\n");
            printf("Please answer Y/y or N/n\n\n");

            printf("Oil Change $119.95? ");
            scanf("%s", choice); //don't do /n after in same statement
              if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                total = total + 119.95;
                }
                else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                  total = total + 0;
                }
                else{
                  printf("Invalid choice entered.\n");
                  printf("Goodbye.\n");
                  return 0;
                }
                printf("Tire alignment $100.00? ");
                scanf("%s", choice); //don't do /n after in same statement
                  if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                    total = total + 100.00;
                    }
                    else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                      total = total + 0;
                    }
                    else{
                      printf("Invalid choice entered.\n");
                      printf("Goodbye.\n");
                      return 0;
                    }
                    printf("Windshield wiper blades $45.95? ");
                    scanf("%s", choice); //don't do /n after in same statement
                      if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                        total = total + 45.95;
                        }
                        else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                          total = total + 0;
                        }
                        else{
                          printf("Invalid choice entered.\n");
                          printf("Goodbye.\n");
                          return 0;
                        }
}
else if ((currentMileage >= 50000) && (currentMileage <= 64999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $119.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 119.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $100.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 100.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
}

else if ((currentMileage >= 65000) && (currentMileage <= 79999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $119.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 119.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $100.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 100.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Windshield wiper blades $45.95? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 45.95;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Engine air filter $40.50? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 40.50;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
                  printf("Brake fluid $104.00? ");
                  scanf("%s", choice); //don't do /n after in same statement
                    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                      total = total + 104.00;
                      }
                      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                        total = total + 0;
                      }
                      else{
                        printf("Invalid choice entered.\n");
                        printf("Goodbye.\n");
                        return 0;
                      }
}


else if ((currentMileage >= 80000) && (currentMileage <= 99999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $119.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 119.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $100.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 100.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Timing belt $345.00? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 345.00;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Transmission fluid $85.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 85.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}

else if ((currentMileage >= 100000) && (currentMileage <= 114999)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $119.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 119.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $100.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 100.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Engine air filter $40.50? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 40.50;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Brake fluid $104.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 104.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}

else if ((currentMileage >= 115000) && (currentMileage <= 500000)){
  printf("Which services should be performed today?\n");
  printf("Please answer Y/y or N/n\n\n");

  printf("Oil Change $119.95? ");
  scanf("%s", choice); //don't do /n after in same statement
    if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
      total = total + 119.95;
      }
      else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
        total = total + 0;
      }
      else{
        printf("Invalid choice entered.\n");
        printf("Goodbye.\n");
        return 0;
      }
      printf("Tire alignment $100.00? ");
      scanf("%s", choice); //don't do /n after in same statement
        if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
          total = total + 100.00;
          }
          else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
            total = total + 0;
          }
          else{
            printf("Invalid choice entered.\n");
            printf("Goodbye.\n");
            return 0;
          }
          printf("Windshield wiper blades $45.95? ");
          scanf("%s", choice); //don't do /n after in same statement
            if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
              total = total + 45.95;
              }
              else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                total = total + 0;
              }
              else{
                printf("Invalid choice entered.\n");
                printf("Goodbye.\n");
                return 0;
              }
              printf("Timing belt $345.00? ");
              scanf("%s", choice); //don't do /n after in same statement
                if ((strcmp(choice,littleYes)==0) || (strcmp(choice,bigYes)==0)){
                  total = total + 345.00;
                  }
                  else if ((strcmp(choice,littleNo)==0) || (strcmp(choice,bigNo)==0)){
                    total = total + 0;
                  }
                  else{
                    printf("Invalid choice entered.\n");
                    printf("Goodbye.\n");
                    return 0;
                  }
}

}//end of trucks
printf("\n\nThe total for your services today is $%.2lf\nGoodbye.\n", (total + (total * 0.05)));


return 0;
}
