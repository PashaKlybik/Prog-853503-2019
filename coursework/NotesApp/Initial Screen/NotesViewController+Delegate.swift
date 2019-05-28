import UIKit

extension NotesViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let controller = NoteDetailController(noteDataSource: self.noteDataSource)
        controller.note = self.notes[indexPath.row]
        self.navigationController?.pushViewController(controller, animated: true)
    }
    
}
