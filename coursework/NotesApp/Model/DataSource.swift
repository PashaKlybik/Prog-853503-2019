import Foundation

protocol DataSource {
    
    func store<T>(object: T)
    func delete<T>(object: T)
    
}

