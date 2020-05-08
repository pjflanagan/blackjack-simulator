# Blackjack Simulator

This program is command line text game that allows a user to play blackjack
with 100 chips. The player wins after obtaining 250 chips. The player
plays alongside an AI that uses the basic strategy but bets randomly, 
and an AI that uses the basic strategy but counts cards to determine a bet.

Also see: [Blackjack Simulator Go](https://github.com/pjflanagan/blackjack-simulator-go)

## Rules

Dealer first shuffles the deck, burns a card, and then deals. There is no cutting
the deck by players in this program. The dealer burns a card at the beginning of 
every turn. The deck is not reshuffled until it is mostly 
empty. Blackjack payout is 3 to 2. Players may not double down after splitting cards.
Players may not surrender. Dealer does not hit on a soft 17.

```
make
make run
```

## To Do

Player add and edit:
- [ ] Dealer should only burn a card ONCE after resetting the deck, and not before each deal
- [ ] PlayerHuman // enters own name
- [ ] PlayerLearner // Plays randomly and records the results
- [ ] Getopt
```
make play
make simulation
```
