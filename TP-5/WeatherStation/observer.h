#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief Observer class
 */
class Observer {
public:
  /**
   * @brief Destructor
   */
  virtual ~Observer() =default;

  /**
   * @brief Function that update the view
   */
  virtual void update() = 0;
};

/**
 * @brief Observable class
 */
class Observable {
public:
  /**
   * @brief Destructor
   */
  virtual ~Observable() =default;

  /**
   * @brief Add observer to the observer list
   * @param observer - observer object to add
   */
  virtual void addObserver(Observer* observer) = 0;

  /**
   * @brief Remove observer to the observer list
   * @param observer - observer to remove from the list
   */
  virtual void removeObserver(Observer* observer) = 0;

  /**
   * @brief Call the 'update' function of all the observers of the list
   */
  virtual void notifyObserver() const = 0;
};

#endif // OBSERVER_H
