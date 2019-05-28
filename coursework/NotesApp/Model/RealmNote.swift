import Foundation
import RealmSwift

class RealmNote : Object {
    
    @objc dynamic var identifier: String = ""
    @objc dynamic var content: String = ""
    @objc dynamic var lastEdited: Date = Date()
    
    override class func primaryKey() -> String? {
        return "identifier"
    }
    
}

extension RealmNote {
    
    convenience init(note: Note) {
        self.init()
        
        self.identifier = note.identifier
        self.content = note.content
        self.lastEdited = note.lastEdited
    }
    
    var note: Note {
        return Note(realmNote: self)
    }
    
}