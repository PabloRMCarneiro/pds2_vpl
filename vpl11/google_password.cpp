#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // Adicionar a url ao mapa de passwords
  if(checkPassword(password)){
    std::map<std::string, Usuario>::iterator it = m_passwords.find(url);
    m_passwords.insert(std::pair<std::string, Usuario>(url, Usuario(login, password)));  
  }
}

void GooglePassword::remove(const std::string& url) {
 /* std::map<std::string, Usuario> :: iterator it = m_passwords.find(url);
  m_passwords.erase(it);*/
  m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
  if (m_passwords.find(url) != m_passwords.end()) {
    if(checkPassword(new_password)){
      if (m_passwords[url].getPassword() == old_password) {
        m_passwords[url].setLogin(login);
        m_passwords[url].setPassword(new_password);
      }
    }
  }
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
  std::cout << m_passwords.size() << std::endl;
  for (auto it = m_passwords.begin(); it != m_passwords.end(); ++it) {
    std::cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << std::endl;
  }

}

bool GooglePassword::checkPassword(const std::string& password) const {
  if (password.size() > 50 || password.size() < 6 || password.find(" ") != std::string::npos || password.find("123456") != std::string::npos) {
    return false;
  }
  else{
    return true;
  }
}


